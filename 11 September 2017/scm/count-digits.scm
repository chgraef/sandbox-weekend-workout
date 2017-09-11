(define (count-digits n)
  (letrec ((helper
             (lambda (m count)
               (if (zero? m) count
                   (let ((next-m (floor (/ m 10))))
                        (helper next-m (+ count 1)))))))
          (helper (abs n) 0)))

(count-digits -1230045)
