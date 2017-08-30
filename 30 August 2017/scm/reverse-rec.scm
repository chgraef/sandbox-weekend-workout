(define (reverse-rec lst)
  (cond [(null? lst) `()]
        [else (append (reverse-rec (cdr lst))
                      (list (car lst)))]))

(define items (list 0 1 2 `(3) 4 5 6 7 8))
(print (reverse-rec items))
