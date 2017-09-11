(define (count-digits n)
  (string-length (number->string (abs n))))

(count-digits -1230045)
