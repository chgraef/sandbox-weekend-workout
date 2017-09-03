(define (map-all-the-things fn lst)
  (if (null? lst) `()
      (cons (let ((x (car lst)))
                 (if (list? x) (map-all-the-things fn x)
                     (fn x))) (map-all-the-things fn (cdr lst)))))

(map-all-the-things (lambda (x) (+ x 1)) `(((1) 2) 3 ()))
