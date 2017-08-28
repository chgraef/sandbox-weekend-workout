; Example 1
((lambda (x) ()) 1)

; Example 2
(map (lambda (x) (* x x)) `(1 2 3 4 5))

; Example 3
(define values `(1 2 3 4 5))
(define total-of-squares
  (apply
    + (map (lambda (x) (* x x)) values)))
  
(print total-of-squares)

; Example 4
(define (sum-squared-two-max x y z)
  (apply + 
    (map (lambda (x) (* x x))
         (cdr (list-sort (list x y z))))))

(print (sum-squared-two-max 6 2 4))
