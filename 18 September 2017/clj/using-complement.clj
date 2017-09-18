(defn my-partition [f lst]
       (concat (list (filter f lst))
               (list (filter (complement f) lst))))

(my-partition odd? (range 10))
; -> ((1 3 5 7 9) (0 2 4 6 8))
