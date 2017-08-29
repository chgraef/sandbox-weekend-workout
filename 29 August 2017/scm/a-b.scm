(define a 5)
(define b 3)

;; The same as:
; (+ (- (* 3 a) b) (+ (* 3 a) b))

(apply + (map (lambda (f) (f (* 3 a) b))
              (list - +)))
