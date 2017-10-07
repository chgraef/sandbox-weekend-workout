(define (replace pred lst fn)
  (if (null? lst) `()
    (let ((x (car lst)))
         (let ((new-x (if (pred x) (fn x) x)))
              (cons new-x (replace pred (cdr lst) fn))))))

(replace zero? `(0 1 0 0 1 2 5 2 1 0 0) (lambda (x) "-"))
