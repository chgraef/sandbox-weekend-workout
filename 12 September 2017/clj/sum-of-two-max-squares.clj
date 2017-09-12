(defn sum-of-squares [x y z]
  (let [squares (map (fn [n] (* n n)) (list x y z))]
       (- (apply + squares)
          (apply min squares))))

(println (sum-of-squares 1 2 3))

