(define (my-append left right)
  (define helper (lambda (left right)
    (if (null? left)
        right
        (helper (cdr left) (cons (car left) right)))))
  (helper (reverse left) right))

(print (my-append (list 1 2 3) (list 4 5 6)))
