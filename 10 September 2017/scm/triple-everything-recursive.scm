;; Repeat every item three times.
;;
;; Recursive solution.

(define (triple-everything lst)
  (if (null? lst) `()
      (append (map (lambda () (car lst)) (iota 3))
              (triple-everything (cdr lst)))))

(triple-everything `(a b c))
