(defn generate-sieve
  ([n] (generate-sieve
         (range 2 n) (int (Math/sqrt n))))
  ([sieve x]
          (if (< x 2) sieve
              (generate-sieve
                (filter #(or (> (mod % x) 0)
                             (= % x))
                        sieve) (dec x)))))

(let [x 102]
     (generate-sieve x))

