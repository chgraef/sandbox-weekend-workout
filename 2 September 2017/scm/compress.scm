(define (compress items)
  (cond [(< (length items) 2) items]
        [(= (car items)
            (cadr items)) (compress (cdr items))]
        [else (cons (car items)
                    (compress (cdr items)))]))

(define empty-list   `())
(define unit-list    `(0))
(define list-of-many `(0 0 0 0))
(define values       `(4 4 4 3 1 2 2 2 0 2 2 2))

(print (compress empty-list))
(print (compress unit-list))
(print (compress list-of-many))
(print (compress values))
