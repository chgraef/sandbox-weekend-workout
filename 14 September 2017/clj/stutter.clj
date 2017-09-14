(defn stutter [lst n]
  (->> (map #(take n (repeat %)) lst)
       (flatten)))
