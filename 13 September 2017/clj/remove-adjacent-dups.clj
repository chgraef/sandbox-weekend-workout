(defn remove-adjacent-dups-rec [lst]
  (if (empty? lst) `()
      (let [x (first lst)]
           (if (= (count lst) 1)
               (list x)
               (let [y (second lst)]
                    (if (= x y)
                        (uniq-rec (rest lst))
                        (cons x (uniq-rec (rest lst)))))))))

(remove-adjacent-dups-rec `(0 0 1 0 0 0 1))
