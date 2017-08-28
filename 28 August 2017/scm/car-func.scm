(define (square x) (* x x))
(define (double x) (* 2 x))

(define x 5)
(define squared
  ((car (list square double)) x))

(print squared)

