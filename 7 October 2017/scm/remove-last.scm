(define (remove-last lst)
  (if (< (length lst) 2) `()
      (cons (car lst) (remove-last (cdr lst)))))
