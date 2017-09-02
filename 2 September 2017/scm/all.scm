(define (all? f items)
  (or (null? items)
      (and (f (car items))
           (or (< (length items) 2)
               (all? f (cdr items))))))

(define animals `("ant" "bear" "cat"))

(all? (lambda (word) (>= (string-length word) 3))
      animals)

(all? (lambda (word) (= (string-length word) 3))
      animals)

(all? (lambda (x) x) `())
