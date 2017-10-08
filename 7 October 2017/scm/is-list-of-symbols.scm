(define (list-of-symbols? lst)
  (if (null? lst) #f
      (let ((x (car lst)))
           (and (symbol? x)
                (or (eq? (length lst) 1)
                    (list-of-symbols? (cdr lst)))))))
