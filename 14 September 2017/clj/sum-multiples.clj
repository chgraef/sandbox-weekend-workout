(defn sum-multiples-of-3-and-5 [lim]
  (->> (range lim)
       (filter #(or (zero? (mod % 3))
                    (zero? (mod % 5))))
       (apply +)))

(let [x 1000]
     (sum-multiples-of-3-and-5 x))
