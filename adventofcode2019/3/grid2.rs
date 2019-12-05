#![allow(non_snake_case)]

use std::io::{self, Read};
use std::collections::VecDeque;

fn manhattan_distance(a: [i16; 2]) -> i32 {
    return (a[0] as i32 - 16384).abs() + (a[1] as i32 - 16384).abs();
}

fn better_point(a: [i16; 2], b: [i16; 2]) -> [i16; 2] {
    if manhattan_distance(a) > manhattan_distance(b) {
        return b;
    }

    return a;
}

fn get_dir_vector(c: char) -> [i16; 2] {
    match c {
        'U' => [1,0],
        'D' => [-1,0],
        'R' => [0,1],
        'L' => [0,-1],
        _ => panic!("Nonexistent direction"),
    }
}

fn add_tuples(mut a: [i16; 2], b: [i16; 2]) -> [i16; 2] {
    a[0] += b[0];
    a[1] += b[1];
    return a;
}

fn main() {
    let mut input = String::with_capacity(4096);
    io::stdin().read_to_string(&mut input);

    let mut grid_raw = vec![false; 32768 * 32768];
    // Vector of 'width' elements slices
    let mut grid_base: Vec<_> = grid_raw.as_mut_slice().chunks_mut(32768).collect();
    // Final 2d array
    let grid: &mut [&mut [_]] = grid_base.as_mut_slice();

    //let mut grid = [[false; 65536]; 65536];
    let mut bestPoint = [i16::max_value(); 2];
    let mut cables: Vec::<Vec::<String>> = input.lines().map(|line| line.split(',').map(|s| String::from(s)).collect()).collect();

    /*
    for (i, line) in input.lines().enumerate() {
        cables[i] = line.split(',').map(|s| String::from(s)).collect();
    }
    */

    let mut pos: [[i16; 2]; 2] = [[16384 as i16; 2]; 2];

    for (step, directions) in cables[0].iter().zip(cables[1].iter()).enumerate() {
        let mut numbers: [i16; 2] = [directions.0[1..].parse().unwrap(), directions.0[1..].parse().unwrap()];
        let vectors: [[i16; 2]; 2] = [
            get_dir_vector(directions.0.chars().next().unwrap()), 
            get_dir_vector(directions.1.chars().next().unwrap())
        ];

        while numbers[0] > 0 && numbers[1] > 0 {
            for i in 0..2 {
                numbers[i] -= 1;
                pos[i] = add_tuples(pos[i], vectors[i]);
                if grid[pos[i][0] as usize][pos[i][1] as usize] == true {
                    bestPoint = better_point(bestPoint, pos[i]);
                }
                grid[pos[i][0] as usize][pos[i][1] as usize] = true;
            }
            if pos[0] == pos[1] {
                println!("{}", step * 2);
            }
        }
        
        let astep = step;
        for i in 0..2 {
            while numbers[i] > 0 {
                numbers[i] -= 1;
                pos[i] = add_tuples(pos[i], vectors[i]);
                if grid[pos[i][0] as usize][pos[i][1] as usize] == true {
                    bestPoint = better_point(bestPoint, pos[i]);
                }
                grid[pos[i][0] as usize][pos[i][1] as usize] = true;
                if pos[0] == pos[1] {
                    println!("{}", astep + step);
                }
            }
        }
    }


    println!("{:?} {}", bestPoint, manhattan_distance(bestPoint));
}

