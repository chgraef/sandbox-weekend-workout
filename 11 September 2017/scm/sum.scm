(define (sum lst)
  (if (null? lst) 0
      (+ (car lst) (sum (cdr lst)))))

(sum (iota 37))
