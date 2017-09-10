;; My lame linear congruential random number generator.
;; Constant values were borrowed from "Numerical recipes", are listed here:
;; [href.] https://en.wikipedia.org/wiki/Linear_congruential_generator#Parameters_in_common_use

(define (make-rand-generator seed)
  (let ((a 1664525)
        (b 1013904223)
        (m (expt 2 32)))
      (let ((x seed))
           (lambda ()
             (set! x (mod (+ (* a x) b) m))
             (/ x (- m 1))))))

(define random (make-rand-generator 0))

(map random (iota 20))
