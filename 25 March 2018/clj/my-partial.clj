(defn my-partial
  "Returns a partial function. It is different from the Clojure's
  (partial ...) function in that it allows gaps in the argument
  list to be filled later, by providing the $ keyword.
  
  (let [split-by-dash (my-partial clojure.string/split :$ #\"#\")]
       (split-by-dash \"dare#edificare#vocare#orare\"))

  It works by building the argument list and applying the f
  function to the newly-constructed argument list."
  { :added "1.0" :static true }
  [f & args]
  (fn [& f-args]
      (let [all-args
            (loop [args     args
                   f-args   f-args
                   res-args []]
                  (if (empty? args) res-args
                      (let [arg          (first args)
                            placeholder? (= arg :$)]
                           (recur (rest args)
                                  (if placeholder? (rest f-args)
                                      f-args)
                                  (if placeholder? (conj res-args (first f-args))
                                      (conj res-args arg))))))]
            (apply f all-args))))

(let [split-by-dash (my-partial clojure.string/split :$ #"#")]
     (split-by-dash "dare#edificare#vocare#orare"))

