; Scheme already has a built-in method that does this, by the way,
; it's called `list-ref`, e.g. `(list-ref `(1 2 3 4) 0) ; => 1`

(define (list-index lst i)
  (if (= i 0)
      (car lst)
      (list-index (cdr lst) (- i 1))))

(define values (list 1 2 3 4))

(print (list-index values 0))
(print (list-index values 1))
(print (list-index values 2))
(print (list-index values 3))
