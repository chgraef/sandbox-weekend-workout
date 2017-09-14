(defn a-plus-b [& values] (apply + values))

(->> (repeat read-line)
     (take 2)
     (map #(%))
     (map #(Integer/parseInt %))
     (apply a-plus-b)
     (println))

