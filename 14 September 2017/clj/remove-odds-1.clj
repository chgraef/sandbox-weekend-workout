; If we did not have `map-indexed`, we would
; probably need to "zip" a sequence of items
; with a range of indices.

(defn remove-odds [lst]
  (->> (map list (range (count lst)) lst)
       (filter (fn [[i x]] (zero? (mod i 2))))
       (map (fn [[i x]] x))))

(remove-odds `(\a \b \c \d \e)) ; -> `(\a \c \e)
