(define (range-of-odd n)
  (if (= n 1) `(1)
      (let ([rest (range-of-odd (- n 1))])
           (let ([last (car (reverse rest))])
                (append rest (list (+ last 2)))))))

(range-of-odd 13)
