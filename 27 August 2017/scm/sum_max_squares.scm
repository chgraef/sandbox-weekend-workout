(define (square x) (* x x))

(define (sum-max-squares x y z)
  (apply +
         (cdr
           (map square (list-sort (list x y z))))))

