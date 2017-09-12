;; Recursive implementation of summing digits.

;; n must be positive or zero, though, if needed
;; support for negative numbers would be trivial
;; to implement.

(define (sum-digits n)
  (if (zero? n) 0
      (let ([m     (floor (/ n 10))]
            [digit (mod n 10)])
           (+ digit (sum-digits m)))))
