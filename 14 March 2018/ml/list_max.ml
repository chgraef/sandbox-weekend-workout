let rec list_max lst =
    match lst with
        | []            -> failwith "list cannot be empty"
        | [mx]          -> mx
        | mx :: x :: tl -> if x > mx then list_max (x :: tl) else list_max (mx :: tl);;

let vals = [4; 1; 3; 2; 5; 7; 3; 4; 1] in
let mx = list_max vals in
print_int mx;;

