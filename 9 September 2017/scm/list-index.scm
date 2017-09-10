(define (take-while fn lst)
  (if (null? lst) `()
      (let ((cur-item (car lst)))
           (if (fn cur-item)
               (cons cur-item (take-while fn (cdr lst)))
               `()))))

(define (list-index fn lst)
  (let ((index (length (take-while (lambda (x) (not (fn x))) lst))))
       (if (eq? index (length lst)) -1
           index)))

(let ((range (iota 10)))
     (for-each print (list (list range)
                           (list-index (lambda (x) (eq? x 9)) range)
                           (list-index (lambda (x) (eq? x 10)) range))))
