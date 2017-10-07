(define (->boolean x)
  (not (not x)))

(define (member? lst x)
  (->boolean (find (lambda (y) (eq? x y)) lst)))
