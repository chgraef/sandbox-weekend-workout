(defn count-letters
  ([s] (count-letters s
                      (apply array-map
                             (flatten (map (fn [c] (list c 0))
                                           s)))))
  ([s counter] (if (empty? s) counter
                   (count-letters (rest s)
                                  (update counter (first s) inc)))))

(count-letters "abrcadadr")
