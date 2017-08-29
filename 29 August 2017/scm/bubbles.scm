; (list 0 1 2 3)
; -> (0 (1 (2 (3))))

(define (bubble-up items)
  (if (< (length items) 2)
      items
      (cons (car items)
            (list (bubble-up (cdr items))))))

(define values (list 0 1 2 3))
(define bubbles (bubble-up values))

(print bubbles)
