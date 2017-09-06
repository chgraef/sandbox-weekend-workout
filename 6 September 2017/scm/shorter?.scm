(define (shorter? left right)
  (cond [(and (null? left)
              (null? right)) #f]
        [(null? left)  #t]
        [(null? right) #f]
        [else (shorter? (cdr left) (cdr right))]))
