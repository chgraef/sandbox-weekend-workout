(define (list-flatten lst)
  (if (null? lst) `()
      (let ((x (car lst)))
           (let ((y (if (list? x)
                        (list-flatten x)
                        (list x)))) (append y (list-flatten (cdr lst)))))))

(define lst `(1 2 ((3)) ((4) 5)))
(list-flatten lst)
