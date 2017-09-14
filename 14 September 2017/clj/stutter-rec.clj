; Let us pretend the "repeat" function
; is not available to us.

(defn stutter [lst n]
  (letfn [(f [x n] (if (zero? n) `()
                       (cons x (f x (dec n)))))]
         (if (empty? lst) `()
             (concat (f (first lst) n)
                     (stutter (rest lst) n)))))

(stutter (range 3) 3)
