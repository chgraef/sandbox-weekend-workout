(define (list-join separator . args)
  (if (= 0 (length args))
      ""
      (string-concat (cons (car args)
          (map (lambda (x) (string-concat (list separator x)))
               (cdr args))))))

(define words     (list "peanut" "butter" "jelly" "scheme!"))
(define separator "-")
(define cadence   (apply list-join (cons separator words)))

(print cadence)
