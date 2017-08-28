(define (count-down n)
  (print n)
  (if (= n 0) 0 (count-down (- n 1))))

(define x 5)
(count-down x)

