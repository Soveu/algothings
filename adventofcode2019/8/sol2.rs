#![allow(non_snake_case)]

const IMG_HEIGHT: usize = 6;
const IMG_WIDTH: usize  = 25;
const IMG_SIZE: usize   = IMG_HEIGHT * IMG_WIDTH;

use std::io::{self, Read};

fn get_input_as_bytes() -> Vec::<u8> {
    let mut input = Vec::with_capacity(4096);
    io::stdin().read_to_end(&mut input).expect("Error reading data");
    return input;
}

fn main() {
    let input = get_input_as_bytes();
    let mut image = ['2' as u8; IMG_SIZE];
    for layer in input.chunks_exact(IMG_SIZE) {
        for (pixel, col) in image.iter_mut().zip(layer.iter()) {
            if *pixel as char == '2' {
                *pixel = *col;
            }
        }
    }

    for row in image.chunks(IMG_WIDTH) {
        for x in row {
            if *x == b'1' {
                print!("█");
            } else {
                print!(" ");
            }
        }
        print!("\n");
    }
}

