(define (compose f1 f2)
  (lambda (x) (f1 (f2 x))))

(define (foo s)
  (string-append s "abc"))

(define (bar s)
  (string-append s "def"))

(define el-ultimo (compose foo bar))
(define str "ghi")

(print (el-ultimo str))

(print (string-concat (reverse
         (string-split (el-ultimo str) ""))))
