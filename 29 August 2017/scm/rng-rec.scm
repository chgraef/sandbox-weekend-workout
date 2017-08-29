(define (range n)
  (define (helper n)
    (if (< 0 n) (cons n (helper (- n 1))) `(0)))
  (reverse (helper n)))

(define x 5)
(define values (range x))

(print values)
