let rec repeat_string str n =
    if (n = 1)
    then str
    else str ^ (repeat_string str (n - 1));;

let greeting =
    let line = "Hello world!\n"
    and n    = 3 in
    repeat_string line n;;

print_string greeting;;
