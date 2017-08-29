(define (list-join separator . args)
  (if (= 0 (length args))
      ""
      (string-concat (cons (car args)
          (map (lambda (x) (string-concat (list separator x)))
               (cdr args))))))

(define cadence (list-join "-" "peanut" "butter" "jelly" "scheme!"))
(print cadence)
