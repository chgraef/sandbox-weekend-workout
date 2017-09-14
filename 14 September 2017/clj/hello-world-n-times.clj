(defn hello-world-n-times [n]
  (clojure.string/join \newline
                       (take n (repeat "Hello World"))))

(let [n 4]
     (->> (hello-world-n-times n)
          (println)))
