(defn remove-odds [lst]
  (->> (map-indexed (fn [i x] [i x]) lst)
       (filter (fn [[i x]] (zero? (mod i 2))))
       (map (fn [[i x]] x))))

(remove-odds `(\a \b \c \d)) ; -> `(\a \c)

