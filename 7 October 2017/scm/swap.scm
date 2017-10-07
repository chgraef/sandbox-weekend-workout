(define (swap lst i j)
  (let ((indices (iota (length lst))))
       (map (lambda (k)
              (cond [(eq? k i) (list-ref lst j)]
                    [(eq? k j) (list-ref lst i)]
                    [else (list-ref lst k)])) indices)))

(define greeting "hello world")
(define words    (string-split "hello world !" " "))

(print (swap words 0 (- (length words) 1)))
