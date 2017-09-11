(define (fibo n)
  (letrec ([helper (lambda (a b n)
                     (if (= n 1) a
                         (helper b (+ a b) (- n 1))))])
       (helper 0 1 n)))

(map fibo (iota 10 1))

;; (iota 10 1) ;=> 1 2 3 4 5 6 7 8 9 10
