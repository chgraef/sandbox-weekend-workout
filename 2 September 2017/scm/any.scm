(define (any? f items)
  (and (not (null? items))
       (or (f (car items))
           (any? f (cdr items)))))

(define animals `("ant" "bear" "cat"))

(any? (lambda (word) (>= (string-length word) 3))
      animals)

(any? (lambda (word) (< (string-length word) 3))
      animals)

(any? (lambda (x) (not (null? x)))`(() () ()))
