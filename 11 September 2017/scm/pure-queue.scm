;; Pure functional queue implementation in Scheme.

(define (make-queue) `())

(define (queue-length q) (length q))

(define (queue-enqueue q item) (append q (list item)))

(define (queue-dequeue q) (cdr q))

(define (queue-last q) (car q))

(let ((queue (make-queue)))
     (for-each (lambda (c) (set! queue (queue-enqueue queue c)))
               (string-split "ABCD" ""))
     (letrec ([traverse-queue (lambda (q)
                                (if (zero? (queue-length q)) `()
                                    (begin (print (queue-last q))
                                           (traverse-queue (queue-dequeue q)))))])
             (traverse-queue queue)))
