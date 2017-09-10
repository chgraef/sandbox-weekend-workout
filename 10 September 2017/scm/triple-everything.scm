;; Repeat every item three times.
;;
;; Non-recursive solution.

(define (triple-everything lst)
  (apply append (map (lambda (x)
                       (map (lambda () x)
                            (iota 3))) lst)))
      
(triple-everything `(a b c))
