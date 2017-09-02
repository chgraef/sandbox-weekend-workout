(define (chunk-eq lst)
  (if (null? lst) `()
      (let ((x    (car lst))
            (rest (chunk-eq (cdr lst))))
           (cond [(null? rest)      (list (list x))]
                 [(= x (caar rest)) (cons (cons x (car rest)) (cdr rest))]
                 [else              (cons (list x) rest)]
               ))))

(define values `(0 1 1 2 3 3 3 0))
(chunk-eq values)

