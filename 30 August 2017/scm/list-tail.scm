(define (my-list-tail lst n)
  (if (= 0 n)
      lst
      (my-list-tail (cdr lst) (- n 1))))

(define values (list 0 1 2 3 4))

(print (list-tail values 3))
(print (my-list-tail values 3))
