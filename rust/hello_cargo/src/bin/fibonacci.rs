use std::io;

fn main() {
    let mut seq = [1; 10];
    let mut cnt = 1;

    let mut sbuf=String::new();

    loop {
        for i in 2..10 {
            seq[i] = seq[i - 1] + seq[i - 2];
        }
        print_seq(&mut cnt, seq);

        io::stdin().read_line(&mut sbuf)
            .expect("Failed to read line");
        if sbuf.trim() == "q" {
            return;
        }
        seq[0]=seq[8]+seq[9];
        seq[1]=seq[0]+seq[9];
    }
}

fn print_seq(cnt: &mut i32, seq: [i32; 10]) {
    print!("seq{cnt}~{}: ", *cnt + 9);
    for n in seq {
        print!(" {n}");
    }
    print!("\n");
    *cnt += 10;
}
