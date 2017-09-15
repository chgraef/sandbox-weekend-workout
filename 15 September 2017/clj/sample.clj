(defn sample [lst]
  (and (not (empty? lst))
       (nth lst (* (count lst) (rand)))))

(run! println [(sample `())
               (sample `("a"))
               (sample "abc")
               (sample (range 5))])
