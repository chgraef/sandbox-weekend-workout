(defn proper-divisors [x]
  (or (butlast (rest (divisors x)))
      `()))

(defn divisors
  ([x]   (divisors x x))
  ([x y] (if (<= y 0) `()
             (let [other-divisors (divisors x (dec y))]
                  (if (zero? (mod x y))
                      (cons y other-divisors)
                      other-divisors)))))

(defn prime? [x]
  (empty? (proper-divisors x)))

(let [x 12
      p 37]
  (println x)
  (println (divisors x))
  (println (proper-divisors x))
  (println (prime? x))
  (newline)
  (println p)
  (println (divisors p))
  (println (proper-divisors p))
  (println (prime? p)))

