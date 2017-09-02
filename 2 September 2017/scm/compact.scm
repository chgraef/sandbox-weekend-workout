(define (compact lst)
  (filter (lambda (x) (not (null? x))) lst))
