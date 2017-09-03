(define (remove-odd-nodes lst)
  (map (lambda (i) (list-ref lst i))
       (filter even? (iota (length lst)))))

(remove-odd-nodes `(1 2 3 4 5))
