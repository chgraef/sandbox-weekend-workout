(define (map-rec f lst)
  (if (null? lst)
      `()
      (cons (f (car lst)) (map-rec f (cdr lst)))))

(define values (list -1 -2 -3 0 1))
(define result (map-rec abs values))

(print result)
