(define (make-rand-generator seed)
  (let ((a 1664525)
        (b 1013904223)
        (m (expt 2 32)))
      (let ((x seed))
           (lambda ()
             (set! x (mod (+ (* a x) b) m))
             (/ x m)))))

(define random (make-rand-generator 0))

(map random (iota 20))
