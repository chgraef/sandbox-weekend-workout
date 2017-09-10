(define (fibo n)
  (define (helper n a b)
    (if (< n 2) a
        (helper (- n 1) b (+ a b))))
  (helper n 0 1))

(define (make-iota-init-args)
  `(10 1))

(map (lambda (n) (fibo n)) (apply iota (make-iota-init-args)))
