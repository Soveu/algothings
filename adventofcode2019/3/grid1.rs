#![allow(non_snake_case)]

use std::io::{self, Read};
use std::collections::VecDeque;

fn manhattan_distance(a: (u16, u16)) -> i32 {
    return (a.0 as i32 - 32768).abs() + (a.1 as i32 - 32768).abs();
}

fn better_point(a: (u16, u16), b: (u16, u16)) -> (u16, u16) {
    if manhattan_distance(a) > manhattan_distance(b) {
        return b;
    }

    return a;
}

fn main() {
    let mut input = String::with_capacity(4096);
    io::stdin().read_to_string(&mut input);

    let mut grid_raw = vec![0 as u8; 65536 * 65536];
    // Vector of 'width' elements slices
    let mut grid_base: Vec<_> = grid_raw.as_mut_slice().chunks_mut(65536).collect();
    // Final 2d array
    let grid: &mut [&mut [_]] = grid_base.as_mut_slice();

    //let mut grid = [[false; 65536]; 65536];
    let mut bestPoint = (u16::max_value(), u16::max_value());

    for (i, cable) in input.lines().enumerate() {
        let mut pos = (32768 as u16, 32768 as u16);

        for direction in cable.split(',') {
            let number: i16 = direction[1..].parse().expect("Wrong number");

            match direction.chars().next().expect("SCREAM FOR HELP") {
                'U' => {
                    for i in 0..number {
                        pos.0 += 1;
                        if grid[pos.0 as usize][pos.1 as usize] == GridItem::JustCable {
                            bestPoint = better_point(bestPoint, pos);
                        }
                        grid[pos.0 as usize][pos.1 as usize] = GridItem::JustCable;
                    }                        
                },
                'D' => {
                    for i in 0..number {
                        pos.0 -= 1;
                        if grid[pos.0 as usize][pos.1 as usize] == GridItem::JustCable{
                            bestPoint = better_point(bestPoint, pos);
                        }
                        grid[pos.0 as usize][pos.1 as usize] = GridItem::JustCable;
                    }                        
                },
                'R' => {
                    for i in 0..number {
                        pos.1 += 1;
                        if grid[pos.0 as usize][pos.1 as usize] == GridItem::JustCable{
                            bestPoint = better_point(bestPoint, pos);
                        }
                        grid[pos.0 as usize][pos.1 as usize] = GridItem::JustCable;
                    }                        
                },
                'L' => {
                    for i in 0..number {
                        pos.1 -= 1;
                        if grid[pos.0 as usize][pos.1 as usize] == GridItem::JustCable{
                            bestPoint = better_point(bestPoint, pos);
                        }
                        grid[pos.0 as usize][pos.1 as usize] = GridItem::JustCable;
                    }                        
                },
                _ => panic!("Nonexistent direction!"),
            }
        }
    }

    println!("{:?} {}", bestPoint, manhattan_distance(bestPoint));
}

