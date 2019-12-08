#![allow(non_snake_case)]

use std::io::{self, Read};

fn get_input_as_bytes() -> Vec::<u8> {
    let mut input = Vec::with_capacity(4096);
    io::stdin().read_to_end(&mut input).expect("Error reading data");
    return input;
}

fn main() {
    let input = get_input_as_bytes();
    let (zeroCount, bestChunk) = input.chunks_exact(25 * 6)
        .map(|c| (c.iter().filter(|x| **x as char == '0').count(), c))
        .min_by(|x,y| x.0.cmp(&y.0))
        .expect("Error calculating min");

    println!("{}", zeroCount);

    let numOfOnes = bestChunk.iter().filter(|b| **b as char == '1').count();
    let numOfTwos = bestChunk.iter().filter(|b| **b as char == '2').count();

    println!("{}", numOfOnes * numOfTwos);
}

