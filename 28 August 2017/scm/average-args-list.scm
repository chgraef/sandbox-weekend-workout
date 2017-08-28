(define (average . args-list)
  (define divisor (length args-list))
  (define sum     (apply + args-list))
  (define result  (/ sum divisor))
  result)

(define divisor (average 1 2 3.01))

(print divisor)
