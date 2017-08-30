(define values (list `(2.123) `(-1) `(("a" "b" "c"))))
(define funcs  (list floor abs string-concat))

(print (map apply funcs values))
