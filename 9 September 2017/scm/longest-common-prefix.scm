(define (longest-common-prefix lst1 lst2)
  (if (or (null? lst1)
          (null? lst2)) `()
      (let ((x (car lst1))
            (y (car lst2)))
           (if (eq? x y)
               (cons x (longest-common-prefix (cdr lst1) (cdr lst2)))
               `()))))

(for-each print
          (list (longest-common-prefix `(a b c) `(a b d f))
                (longest-common-prefix `(s t e r n) `(s t e r n u m))
                (longest-common-prefix `(1 2 3) `(0 1 2 3))))
