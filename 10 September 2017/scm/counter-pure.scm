;; [href.] http://www.scheme.com/tspl4/start.html#./start:s186
;;
;; Exercise 2.9.1
;;
;; Modify make-counter to take two arguments: an initial value
;; for the counter to use in place of 0 and an amount to increment
;; the counter by each time.

;; K.I.S.S. functional and pure. Makes use of an extra predicate
;; parameter to determine when to halt. This will use extra RAM
;; due to all values being returned at once.

(define (make-counter start step can-stop?)
  (if (can-stop? start) `()
      (cons start (make-counter (+ start step)
                                step
                                can-stop?))))

(define (make-counter-init-args)
  (list 2 5 (lambda (x) (> x 37))))

(let ((counter (apply make-counter
                      (make-counter-init-args)))) counter)

