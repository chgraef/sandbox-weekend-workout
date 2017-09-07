; `((1 . a) (2 . b) (3 . c)) -> `((a b c) 1 2 3)
;
(define (transpose pairs)
  (append
    (list (map (lambda (pair) (cdr pair)) pairs))
    (map (lambda (pair) (car pair)) pairs)))

(define pairs `((1 . a) (2 . b) (3 . c)))
(transpose pairs)
