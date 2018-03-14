let rec list_merge lst1 lst2 = match lst1 with
    | []       -> lst2
    | hdx::tlx -> match lst2 with
        | []       -> lst1
        | hdy::tly -> if hdx < hdy then
                          hdx :: list_merge tlx lst2
                      else
                          hdy :: list_merge lst1 tly;;

let vals = list_merge [1; 3; 4; 5] [3; 7];;

let rec list_print = (fun to_s sep lst -> match lst with
    | []     -> print_newline ()
    | [x]    -> print_string (to_s x)
    | hd::tl -> begin
                    print_string (to_s hd);
                    print_string sep;
                    list_print to_s sep tl
                end);
    in (list_print string_of_int "|" vals);;
