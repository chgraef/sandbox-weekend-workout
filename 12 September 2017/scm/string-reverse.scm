(define (string-reverse s)
  (if (= (string-length s) 0) ""
      (let ([char (substring s 0 1)]
            [rest (substring s 1 (string-length s))])
           (string-concat (append (list (string-reverse rest))
                                  (list char))))))


(string-reverse "abcdefghijkl")
