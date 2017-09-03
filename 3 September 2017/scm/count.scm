(define (chunk-eq lst)
  (if (< (length lst) 2) (list lst)
      (let ((rest (chunk-eq (cdr lst)))
           (x    (car lst)))
           (if (eq? x (caar rest)) (cons (cons x (car rest)) (cdr rest))
               (cons (list x) rest)))))

(define (count lst)
  (let ((sorted (list-sort (filter (lambda (x) (not (null? x))) lst))))
       (map (lambda (group) (list (car group) (length group)))
            (chunk-eq sorted))))

(count (list "G" "A" "A" "T" "C" "G" "C" `() "G"))

