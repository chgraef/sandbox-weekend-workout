(define (times n f)
  (if (or (zero? n)
          (negative? n))
      `()
      (cons (f) (times (- n 1) f))))

(define (string-join separator strings)
  (cond [(null? strings) ""]
        [(< (length strings) 2) (car strings)]
        [else (string-append
                (car strings)
                separator
                (string-join separator (cdr strings)))]))

(print (string-join "\n" (times 10 (lambda () "Not it"))))
