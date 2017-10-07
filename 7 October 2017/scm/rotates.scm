(define (list-head lst n)
  (if (zero? n) `()
      (cons (car lst) (list-head (cdr lst) (- n 1)))))

(define rotate-left
  (lambda (lst n)
    (append (list-tail lst n)
            (list-head lst n))))

(define rotate-right
  (lambda (lst n)
    (append (list-head lst n)
            (list-tail lst n))))

(define values (iota 10))
(define n 3)

(let ((values (iota 10))
      (n      3))
    (for-each print (list (rotate-left  values n)
                          (rotate-right values n))))
