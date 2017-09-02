(define (zip . lists)
  (if (or (null? lists)
          (positive? (length (filter
                               (lambda (lst) (null? lst))
                               lists)))) `()
    (cons (map car lists)
          (apply zip (map cdr lists)))))

