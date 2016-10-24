let mothers =
  ['m' ; 'o' ; 't' ; 'h' ; 'e' ; 'r' ; 'M' ; 'O' ; 'T' ; 'H' ; 'E' ; 'R']

let rec hasMother mothers str =
  match mothers with
  | [] -> false
  | h :: t -> String.contains str h || hasMother t str

let rec main () =
  try
    let line = read_line() in
    let new_line = if hasMother mothers line then String.uppercase line
                   else String.lowercase line in
    let () = print_string new_line in
    let () = print_newline () in
    main ()
  with End_of_file -> ();;

let () = main()
