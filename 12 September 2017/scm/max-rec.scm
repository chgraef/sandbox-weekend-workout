;; Let's assume, for a moment, that Scheme does not
;; have a builtin max function...

(define (max-of-two x y)
  (if (> x y) x y))

(define (max-rec lst)
  (if (null? lst) `()
      (let ([x (car lst)])
           (if (= (length lst) 1) x
               (apply max-of-two (cons x (list (max-rec (cdr lst)))))))))

(max-rec `(10 0 1 2 -1 -1 -1 5 500 2 1 -100 10))

