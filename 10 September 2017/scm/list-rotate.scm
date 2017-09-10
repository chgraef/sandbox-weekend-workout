(define (list-head lst n)
  (if (zero? n) `()
      (cons (car lst)
            (list-head (cdr lst)
                       (- n 1)))))

(define (list-left-rotate lst n)
  (append (list-tail lst n)
          (list-head lst n)))

(define (list-right-rotate lst n)
  (let ((m (- (length lst) n)))
       (append (list-tail lst m)
               (list-head lst m))))
