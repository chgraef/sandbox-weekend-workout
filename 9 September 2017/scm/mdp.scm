;; [href.] https://see.stanford.edu/materials/icsppcs107/38-CS107-Practice-Final.pdf
;;
;; Function: mdp
;; -------------
;; Mapping routine which transforms a list of length n into another
;; list of length n, where each element of the new list is the result
;; of levying the specified func against the corresponding cdr of
;; the original.

(define (mdp f lst)
  (map f (map (lambda (i) (list-tail lst i))
       (iota (length lst)))))

(for-each print (list (mdp length  `(w x y z))
                      (mdp cdr     `(2 1 2 8))
                      (mdp reverse `("ba" "de" "foo" "ga")))

