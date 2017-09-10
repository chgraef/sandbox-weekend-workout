;; [href.] http://www.scheme.com/tspl4/start.html#./start:s186
;;
;; Exercise 2.9.1
;;
;; Modify make-counter to take two arguments: an initial value
;; for the counter to use in place of 0 and an amount to increment
;; the counter by each time.

;; Counter as an abstract data compound (i.e. class).

;; Amabo te note: this code is merely an exploration of data
;; abstraction methods in LISP/Scheme. Counter is used merely
;; as an example. In real-life programming, I agree, this
;; would probably be an overkill.

(define (make-counter start step)
  (cons start step))

(define (counter-value counter)
  (car counter))

(define (counter-step counter)
  (cdr counter))

(define (counter-next counter)
  (let ((value (counter-value counter))
        (step  (counter-step  counter)))
       (make-counter (+ value step) step)))

(define (make-counter-init-args)
  `(0 5))

(let ((can-stop? (lambda (counter)
                   (>= (counter-value counter) 37))))
     (let ((f (lambda (self counter)
                (if (can-stop? counter) `()
                    (let ((cur-counter (counter-next counter)))
                         (cons cur-counter (self self cur-counter)))))))
          (map (lambda (counter) (counter-value counter))
               (f f (apply make-counter (make-counter-init-args)))))
