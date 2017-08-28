(define (push lst x)
  (reverse (cons x (reverse lst))))

(define items (list 1 2 3))
(define new-item 4)
(define more-items (push items new-item))

(print more-items)

