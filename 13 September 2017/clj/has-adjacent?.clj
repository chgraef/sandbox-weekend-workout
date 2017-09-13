(defn has-adjacent? [lst x]
  (boolean (some (fn [[a _b]] (= x a))
                 (filter (fn [[a b]] (= a b))
                         (map list lst (rest lst))))))

(has-adjacent? `() 5)
(has-adjacent? `(5 7 5 7) 5)
(has-adjacent? `(5 7 7 5) 5)
(has-adjacent? `(5 5 7 7) 5)
(has-adjacent? `(7 5 5 5) 5)
(has-adjacent? `(5 5 7 7) 7)
