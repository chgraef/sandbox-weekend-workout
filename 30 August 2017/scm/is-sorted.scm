; or just: (< 0 1 2 3 4)
; :)

(define (sorted? lst)
  (or (< (length lst) 2)
      (and (<= (car lst) (cadr lst))
           (sorted? (cdr lst)))))

(define lists `(()
                (1)
                (1 1)
                (1 2)
                (1 -1)
                (0 0 0)))

(print (map sorted? lists))
