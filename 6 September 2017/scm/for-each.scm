(define (my-mod x y)
  (if (> y x) x
      (my-mod (- x y) y)))

(define (rly-even? x)
  (zero? (my-mod x 2)))

(define range (iota 10))

(for-each print
  (map (lambda (pair)
         (let ((x (cadr pair))
               (is-even (car pair)))
              (if is-even (list x "is even")
                    (list x "is odd"))))
       (map list (map rly-even? range) range)))
