let rec list_merge lst1 lst2 = match lst1 with
    | []     -> lst2
    | hd::tl -> match lst2 with
        | []     -> lst1
        | hd::tl -> let x = List.hd lst1
                    and y = List.hd lst2 in
                    if x < y then
                        x :: list_merge (List.tl lst1) lst2
                    else
                        y :: list_merge lst1 (List.tl lst2);;

let vals = list_merge [1; 3; 4; 5] [3; 7];;

let rec list_print = (fun to_s sep lst -> match lst with
    | []     -> print_newline ()
    | [x]    -> print_string (to_s x)
    | hd::tl -> begin
                    print_string (to_s hd);
                    print_string sep;
                    list_print to_s sep (List.tl lst)
                end);
    in (list_print string_of_int "|" vals);;
