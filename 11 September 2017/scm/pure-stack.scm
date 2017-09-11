;; Kind of slow, but pure functional stack in Scheme.

(define (make-stack) `())

(define (stack-length stack) (length stack))

(define (stack-push stack item)
  (reverse (cons item (reverse stack))))

(define (stack-pop stack)
  (reverse (cdr (reverse stack))))

(define (stack-last stack)
  (car (reverse stack)))

(let ([stack (make-stack)])
     (for-each (lambda (c) (set! stack (stack-push stack c)))
               (string-split "ABCD" ""))
     (letrec ([traverse-stack (lambda (stk)
                                (if (zero? (stack-length stk)) `()
                                    (begin (print (stack-last stk))
                                           (traverse-stack (stack-pop stk)))))])
             (traverse-stack stack)))
