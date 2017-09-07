(define (string-format fmt-str options)
  (let ((fmt-token "{}")
        (fmt-str-len (string-length fmt-str)))
      (if (zero? (string-length fmt-str)) fmt-str
          (let ((str-token (substring fmt-str 0
                                      (min (string-length fmt-token)
                                           fmt-str-len))))
            (if (string=? str-token fmt-token)
                (let ((str-rest (substring fmt-str
                                     (min (string-length fmt-token)
                                          fmt-str-len)
                                     fmt-str-len)))
                     (string-concat (list (car options)
                                          (string-format str-rest (cdr options)))))
                (string-concat (list (car (string-split fmt-str ""))
                                     (string-format (substring fmt-str 1
                                                               fmt-str-len)
                                                    options))))))))

(string-format "{}  {}! {}, {} is it {}ing?" `("Ave" "W" 123 "How" "go"))
