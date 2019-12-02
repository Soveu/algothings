use std::io::{self, Read};

fn str_to_int(s: &str) -> i64 {
    return s.trim().parse::<i64>().expect("Invalid number");
}

fn part1(mut tape: Vec<i64>) -> i64 {
    let mut headerPos: usize = 0;
    loop {
        match tape[headerPos] {
            1 => {
                let arg1 = tape[headerPos+1] as usize;
                let arg2 = tape[headerPos+2] as usize;
                let arg3 = tape[headerPos+3] as usize;
                tape[arg3] = tape[arg2] + tape[arg1];
            },
            2 => {
                let arg1 = tape[headerPos+1] as usize;
                let arg2 = tape[headerPos+2] as usize;
                let arg3 = tape[headerPos+3] as usize;
                tape[arg3] = tape[arg2] * tape[arg1];
            },
            99 => break,
            _ => { println!("SCREAM FOR HELP"); },
        }

        headerPos += 4;
    }

    return tape[0];
}

fn part2(tape: &mut Vec<i64>) -> i64 {
    for a in 0..99 {
        tape[1] = a;
        for b in 0..99 {
            tape[2] = b;

            if(part1(tape.clone()) == 19690720) {
                return 100 * a + b;
            }
        }
    }

    return -1;
}

fn main() {
    let mut input = String::with_capacity(4096);
    io::stdin().read_to_string(&mut input);
    let mut tape: Vec<i64> = input.split(',').map(str_to_int).collect();

    tape[1] = 12;
    tape[2] = 2;
    println!("{}", part2(&mut tape));
}

