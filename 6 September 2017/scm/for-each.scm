(define (rly-even? x)
  (zero? (mod x 2)))

(define range (iota 10))

(for-each print
  (map (lambda (pair)
         (let ((x (cadr pair)))
              (if x (list x "is even")
                    (list x "is odd"))))
       (map list (map rly-even? range) range)))
