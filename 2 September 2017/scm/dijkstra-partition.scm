(define (partition x items)
  (append (filter (lambda (y) (< y x)) items)
          (filter (lambda (y) (= y x)) items)
          (filter (lambda (y) (> y x)) items)))
