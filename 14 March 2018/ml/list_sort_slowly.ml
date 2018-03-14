let rec list_insert_sorted lst x =
    match lst with
        | []       -> [x]
        | hd :: tl -> if x <= hd then
                          x :: hd :: tl
                      else
                          hd :: list_insert_sorted tl x;;

let list_sort_slowly lst =
    let rec list_sort_slowly_helper res lst =
        (match lst with
             | []       -> res
             | hd :: tl -> let new_res = list_insert_sorted res hd in
                           list_sort_slowly_helper new_res tl);
    in list_sort_slowly_helper [] lst;;
