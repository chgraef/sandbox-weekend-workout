(define (make-list n)
  (if (< n 1)
      `()
      (append (list `()) (make-list (- n 1)))))

(make-list 7)
