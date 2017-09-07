(define (next)
  (define (helper x)
    (list x (lambda () (helper (+ 1 x)))))
  (helper 0))

; example usage
(define f (lambda (g)
  (let ((pair (g)))
       (let ((x (car  pair))
             (h (cadr pair)))
          (if (< x 101) (and (print x) (f h))))))) ; could use a predicate instead of (< x 101)

(f next)
