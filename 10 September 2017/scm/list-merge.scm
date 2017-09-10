;; Problem definition taken from:
;; [href.] https://see.stanford.edu/materials/icsppcs107/31-Functions-As-Data.pdf
;;
;; Code here by yours truly.
;;
;; Function: merge
;; ---------------
;; Takes the two lists, each of which is assumed to be sorted
;; according to the specified comparator function, and synthesizes
;; an fresh list which is the sorted merge of the incoming two.

(define (merge comp lst1 lst2)
  (cond [(and (null? lst1)
              (null? lst2)) `()]
        [(null? lst1) lst2]
        [(null? lst2) lst1]
        [else (let ((x (car lst1))
                    (y (car lst2)))
                   (if (comp x y)
                       (cons x (merge comp (cdr lst1) lst2))
                       (cons y (merge comp lst1 (cdr lst2)))))]))

(for-each print (list (merge (lambda (x y) (< x y))
                             `(-1 5 100) `(3 75))
                      (merge (lambda (x y) (< x y))
                             `(-1 5 100) `())
                      (merge (lambda (x y) (< x y))
                             `() `(3 75))))
