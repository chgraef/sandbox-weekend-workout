(defn peano-sum [a b]
  (cond (zero? a) b
        (zero? b) a
        :else (if (or (and (< a 0)
                           (< b 0))
                      (and (> a 0)
                           (> b 0))) (recur (inc a) (dec b))
                  (recur (inc (min a b)) (dec (max a b))))))
