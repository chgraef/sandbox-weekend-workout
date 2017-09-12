(define (gcd n m)
  (if (zero? m) n
      (gcd m (mod n m))))

(for-each print (list (gcd 1  1)
                      (gcd 12 9)
                      (gcd 12 8)
                      (gcd 12 13)
                      (gcd 13 12)
                      (gcd 12 12)
                      (gcd 9  6)))
