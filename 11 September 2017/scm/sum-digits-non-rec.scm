(define (sum-digits n)
  (apply + (map string->number
                (string-split (number->string (abs n))
                              ""))))

(sum-digits -1230045)
