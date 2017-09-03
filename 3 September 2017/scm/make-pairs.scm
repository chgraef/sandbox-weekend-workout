(define (make-pairs lst)
  (let ((lst-length (length lst)))
       (cond [(zero? lst-length) `()]
             [(= lst-length 1)   (list lst)]
             [else (append (list (list (car lst) (cadr lst)))
                           (make-pairs (cddr lst)))])))

(make-pairs `())
(make-pairs `(1))
(make-pairs `(1 2))
(make-pairs `(1 2 3))
(make-pairs `(1 2 3 4))
