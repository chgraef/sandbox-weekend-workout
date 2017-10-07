(define (list-sublist lst start stop)
  (let ((sublen (- (min stop (length lst)) start)))
       (map (lambda (i) (list-ref lst i)) (iota sublen start))))

(define (list-head lst n)
  (list-sublist lst 0 n))
