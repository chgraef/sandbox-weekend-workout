(define (decimal->binary x)
  (if (zero? x) "0"
      (let ([bit  (number->string (mod x 2))]
            [rest (floor (/ x 2))])
          (string-concat
            (append (list (if (zero? rest) ""
                              (decimal->binary rest)))
                    (list bit))))))

(decimal->binary 66)
