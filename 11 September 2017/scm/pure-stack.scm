;; Pure functional stack implementation in Scheme.

(define (make-stack) `())

(define (stack-length stack) (length stack))

(define (stack-push stack item)
  (cons item stack))

(define (stack-pop stack)
  (cdr stack))

(define (stack-last stack)
  (car stack))

(let ([stack (make-stack)])
     (for-each (lambda (c) (set! stack (stack-push stack c)))
               (string-split "ABCD" ""))
     (letrec ([traverse-stack (lambda (stk)
                                (if (zero? (stack-length stk)) `()
                                    (begin (print (stack-last stk))
                                           (traverse-stack (stack-pop stk)))))])
             (traverse-stack stack)))

