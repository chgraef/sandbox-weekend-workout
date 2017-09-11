(define (natural-range n)
  (if (zero? n) `()
      (append (natural-range (- n 1))
              (list n))))

(let ((n 37)) (natural-range n))
