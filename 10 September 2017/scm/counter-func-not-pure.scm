;; [href.] http://www.scheme.com/tspl4/start.html#./start:s186
;;
;; Exercise 2.9.1
;;
;; Modify make-counter to take two arguments: an initial value
;; for the counter to use in place of 0 and an amount to increment
;; the counter by each time.

;; K.I.S.S. functional, but not quite pure due to call to set!

(define (make-counter start step)
  (let ((next start))
       (lambda () (let ((x next))
                       (set! next (+ next step))
                       x))))

(define (make-counter-init-args)
  `(2 5))

(let ((range   (iota 10))
      (counter (apply make-counter (make-counter-init-args))))
     (map counter range))
