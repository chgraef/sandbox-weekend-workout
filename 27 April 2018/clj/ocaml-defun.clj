;; 2018-04-27 lilsweetcaligula
;;
;; --- OCaml-ish function definition ---
;;
;; The defun macro, given a non-exhaustive list of parameters, returns
;; a partial function. E.g. this:
;; (defun sum-of-three [x y z] (+ x y z))
;;
;; is equivalent to this:
;; (defn sum-of-three
;;   ([x]     (partial sum-of-three x))
;;   ([x y]   (partial sum-of-three x y))
;;   ([x y z] (+ x y z)))
;;
;; The following calls are equivalent:
;; ((((sum-of-three) 2) 3) 5) ;; #=> 10
;; (((sum-of-three 2) 3) 5) ;; #=> 10
;; ((sum-of-three 2 3) 5) ;; #=> 10
;; (sum-of-three 2 3 5) ;; #=> 10

(defmacro defun [fun-name fun-args fun-def]
  (let [defs (->> (range (inc (count fun-args)))
                  (map (fn [num-args]
                           (let [args (vec (take num-args fun-args))]
                                (if (not= num-args (count fun-args))
                                    `(~args (partial ~fun-name ~@args))
                                    `(~args ~fun-def))))))]
       (concat [`defn fun-name] defs)))

;; (macroexpand `(defun foo [x y] (+ 1 x y)))
