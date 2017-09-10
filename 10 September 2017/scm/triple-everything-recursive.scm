;; Original problem defined at:
;; [href.] https://see.stanford.edu/materials/icsppcs107/30-Scheme-Functions.pdf
;;
;; Recursive solution.

(define (triple-everything lst)
  (if (null? lst) `()
      (append (map (lambda () (car lst)) (iota 3))
              (triple-everything (cdr lst)))))

(triple-everything `(a b c))
