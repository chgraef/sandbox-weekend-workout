(define (remv x lst)
  (cond [(null? lst) `()]
        [(= x (car lst)) (remv x (cdr lst))]
        [else (cons (car lst) (remv x (cdr lst)))]))

(define lst (list 1 2 3 5))
(define val 3)

(print (remv val lst))
