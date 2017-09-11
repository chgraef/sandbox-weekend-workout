(define (repeat fn n)
  (map fn (iota n)))

(define (left-justify str n)
  (string-concat (cons str (repeat (lambda (x) " ")
                                   (- n (string-length str))))))

(let ((message "air-speed of unladen swallow")
      (width   32))
     (let ((full-text (left-justify message width)))
          (display full-text)
          (display "!!!")
          (newline)))

