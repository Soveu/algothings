use std::io::{self, Read};

type Intcode = i64;

struct IntcodeMachine {
    tape:   Vec::<Intcode>,
    ip:     usize,
}

type IntcodeInstruction = fn(&mut IntcodeMachine) -> String;

fn get_params(im: &mut IntcodeMachine, n: usize, fname: &str) -> (Vec::<i64>, String) {
    let mut params = Vec::<i64>::with_capacity(n);
    let mut s = String::with_capacity(16);
    let mut modes = im.tape[im.ip] / 100;

    s.push_str(fname);
    s.push('\t');
    im.ip += 1;

    for _ in 1..n {
        let param = match modes % 10 {
            1 => im.tape[im.ip],
            0 => {
                s.push_str(&format!("[{}]=", im.tape[im.ip]));
                im.tape[im.tape[im.ip] as usize]
            },
            _ => panic!("Invalid mode"),
        };

        params.push(param);
        s.push_str(&format!("{}, ", param));
        modes /= 10;
        im.ip += 1;
    }

    let lastParam = match modes % 10 {
        1 => im.tape[im.ip],
        0 => {
            s.push_str(&format!("[{}]=", im.tape[im.ip]));
            im.tape[im.tape[im.ip] as usize]
        },
        _ => panic!("Invalid mode"),
    };
    params.push(lastParam);
    s.push_str(&lastParam.to_string());
    im.ip += 1;

    return (params, s);
}

fn add(im: &mut IntcodeMachine) -> String {
    let (params, mut s) = get_params(im, 2, "ADD");
    let index = im.tape[im.ip] as usize;
    let val = params[0] + params[1];
    im.tape[index] = val;
    s.push_str(&format!(", [{}]={}", index, val));

    im.ip += 1;
    return s;
}
fn mul(im: &mut IntcodeMachine) -> String {
    let (params, mut s) = get_params(im, 2, "MUL");
    let index = im.tape[im.ip] as usize;
    let val = params[0] * params[1];
    im.tape[index] = val;
    s.push_str(&format!(", [{}]={}", index, val));

    im.ip += 1;
    return s;
}
fn input(im: &mut IntcodeMachine) -> String {
    im.ip += 1;
    let index = im.tape[im.ip] as usize;
    let s = format!("INPUT [{}]", index);
    im.tape[index] = 1;
    im.ip += 1;
    return s;
}
fn output(im: &mut IntcodeMachine) -> String {
    let (_, s) = get_params(im, 1, "OUTPUT");
    return s;
}
fn jump_true(im: &mut IntcodeMachine) -> String {
    let (params, mut s) = get_params(im, 2, "JTRUE");
    if params[0] != 0 {
        s.push_str(&format!(" --> {}", params[1]));
        im.ip = params[1] as usize;
    }
    return s;
}
fn jump_false(im: &mut IntcodeMachine) -> String {
    let (params, mut s) = get_params(im, 2, "JFALSE");
    if params[0] == 0 {
        s.push_str(&format!(" --> {}", params[1]));
        im.ip = params[1] as usize;
    }
    return s;
}
fn cmp_lt(im: &mut IntcodeMachine) -> String {
    let (params, mut s) = get_params(im, 2, "CMP_LT");
    let index = im.tape[im.ip] as usize;
    let val = match params[0] < params[1] {
        true => 1,
        false => 0,
    };
    im.tape[index] = val;
    s.push_str(&format!(", [{}]={}", index, val));
    im.ip += 1;

    return s;
}
fn cmp_eq(im: &mut IntcodeMachine) -> String {
    let (params, mut s) = get_params(im, 2, "CMP_LT");
    let index = im.tape[im.ip] as usize;
    let val = match params[0] == params[1] {
        true => 1,
        false => 0,
    };
    im.tape[index] = val;
    im.ip += 1;
    s.push_str(&format!(", [{}]={}", index, val));

    return s;
}

fn match_instruction(x: Intcode) -> Option::<IntcodeInstruction> {
    match x {
        1 => Some(add),
        2 => Some(mul),
        3 => Some(input),
        4 => Some(output),
        5 => Some(jump_true),
        6 => Some(jump_false),
        7 => Some(cmp_lt),
        8 => Some(cmp_eq),
        99 => None,
        _ => panic!(format!("No such instruction: {}", x)),
    }
}

impl Iterator for IntcodeMachine {
    type Item = String;
    fn next(self: &mut Self) -> Option<Self::Item> {
        match match_instruction(self.tape[self.ip] % 100) {
            None => None,
            Some(f) => Some(f(self)),
        }
    }
}

fn main() {
    let mut buffer = String::with_capacity(4096);
    io::stdin().read_to_string(&mut buffer);

    let mut im = IntcodeMachine{
        tape: buffer.split(',').map(|s| s.trim().parse().unwrap()).collect(),
        ip: 0,
    };

    for instruction in im {
        println!("{}", instruction);
    }
}
