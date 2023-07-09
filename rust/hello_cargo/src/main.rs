use std::io;

enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter,
}

fn main() {
    let a = [1, 2, 3, 4, 5];
    for n in a {
        println!("{}", n);
    }
    for n in a {
        println!("{}", n);
    }

    let mut s: &str="hello world";
    println!("s={}", s.replace("o", "i"));
    // let s= String::from("hello world");

    // s.as_bytes().iter().enumerate()
    // s.len();
}

fn value_in_cents(coin: Coin) -> u8 {
    match coin {
        Coin::Penny => {
            println!("Lucky penny!");
            1
        }
        Coin::Nickel => 5,
        Coin::Dime => 10,
        Coin::Quarter => 25,
    }
}
