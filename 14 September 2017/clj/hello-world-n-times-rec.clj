(defn hello-world-n-times-rec [n]
  (if (zero? n) ""
      (cons "Hello World"
            (hello-world-n-times-rec (dec n)))))
