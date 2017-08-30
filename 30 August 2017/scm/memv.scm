(define (memv x lst)
  (cond ((null? lst)    `())
        ((= x (car lst)) lst)
        (else (memv x (cdr lst)))))

(define lst (list 1 2 5 7 9 11))
(define val 7)

(print (memv val lst))
