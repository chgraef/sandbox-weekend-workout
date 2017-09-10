;; Original problem defined at:
;; [href.] https://see.stanford.edu/materials/icsppcs107/30-Scheme-Functions.pdf
;;
;; Non-recursive solution.

(define (triple-everything lst)
  (apply append (map (lambda (x)
                       (map (lambda () x)
                            (iota 3))) lst)))
      
(triple-everything `(a b c))
