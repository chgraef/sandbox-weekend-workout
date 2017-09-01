(define (count-bobs str)
  (define target "bob")
  (length
    (filter (lambda (substr) (string=? substr target))
            (map (lambda (i)
                   (substring str i
                              (min (string-length str)
                              (+ i (string-length target)))))
                  (iota (string-length str))))))

(define str       "bsbobobobababaobobobobabobsb")
(define bob-count (count-bobs str))

(print bob-count)
