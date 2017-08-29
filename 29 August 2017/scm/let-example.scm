(define a 5)
(define b 3)

;; Same as:
; (+ (- (* 3 a) b) (+ (* 3 a) b))

(let ((x (* 3 a))) (+ (- x b) (+ x b)))
