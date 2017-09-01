(define (destroy-all-the-fun str)
  (apply string-append
    (string-split str "fun")))

(define str "dysfunfuncti   fun nal")
(destroy-all-the-fun str)

