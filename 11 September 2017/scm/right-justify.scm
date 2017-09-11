(define (repeat fn n)
  (map (lambda (_x) (fn)) (iota n)))

(define (right-justify str n)
  (string-concat (append (repeat (lambda () " ")
                                 (- n (string-length str)))
                         (list str))))

(let ((message "air-speed of unladen swallow")
      (width   32))
     (let ((full-text (right-justify message width)))
          (display full-text)
          (display "!!!")
          (newline)))
