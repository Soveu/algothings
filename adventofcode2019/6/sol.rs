#![allow(non_snake_case)]

use std::collections::{VecDeque, HashMap};
use std::io::{self, Read};

fn get_all_input() -> String {
    let mut input = String::with_capacity(4096);
    io::stdin().read_to_string(&mut input).expect("Error reading data");
    return input;
}

fn unique_planets<'a>(s: &'a str) -> HashMap::<&'a str, usize> {
    let mut m = HashMap::<&'a str, usize>::new();

    for line in s.lines() {
        let i = match line.find(')') {
            Some(n) => n,
            None => panic!("Error parsing input!"),
        };

        let (s1, s2) = line.split_at(i);
        if !m.contains_key(s1) {
            m.insert(s1, m.len());
        }
        if !m.contains_key(&s2[1..]) {
            m.insert(&s2[1..], m.len());
        }
    }

    return m;
}

type Graph = Vec::<Vec::<usize>>;

fn get_graph<'a>(input: &'a str, m: &HashMap::<&'a str, usize>) -> Graph {
    let mut g = Graph::new();
    g.resize(m.len(), Vec::<usize>::new());
    for line in input.lines() {
        let i = match line.find(')') {
            Some(n) => n,
            None => panic!("Error parsing input!"),
        };

        let (s1, s2) = line.split_at(i);
        let p1 = match m.get(s1) {
            Some(n) => *n,
            None => panic!(format!("Planet not found: {}", s1)),
        };
        let p2 = match m.get(&s2[1..]) {
            Some(n) => *n,
            None => panic!(format!("Planet not found: {}", &s2[1..])),
        };

        g[p1].push(p2);
    }

    return g;
}

fn get_graph_part2<'a>(input: &'a str, m: &HashMap::<&'a str, usize>) -> Graph {
    let mut g = Graph::new();
    g.resize(m.len(), Vec::<usize>::new());
    for line in input.lines() {
        let i = match line.find(')') {
            Some(n) => n,
            None => panic!("Error parsing input!"),
        };

        let (s1, s2) = line.split_at(i);
        let p1 = match m.get(s1) {
            Some(n) => *n,
            None => panic!(format!("Planet not found: {}", s1)),
        };
        let p2 = match m.get(&s2[1..]) {
            Some(n) => *n,
            None => panic!(format!("Planet not found: {}", &s2[1..])),
        };

        g[p1].push(p2);
        g[p2].push(p1);
    }

    return g;
}


fn count_dfs(g: &Graph, n: usize) -> usize {
    let mut sum = 0 as usize;
    let mut stack = Vec::<(usize, usize)>::new();
    let mut visited = Vec::<bool>::new();
    visited.resize(g.len(), false);

    stack.push((n, 0));
    loop {
        let (currentN, counter) = match stack.pop() {
            Some(x) => x,
            None => break,
        };
        visited[currentN] = true;
        sum += counter;

        for child in &g[currentN] {
            if !visited[*child] {
                stack.push((*child, counter+1));
            }
        }
    }

    return sum;
}

fn count_bfs(g: &Graph, source: usize, dest: usize) -> usize {
    let mut q = VecDeque::<(usize, usize)>::new();
    let mut visited = Vec::<bool>::new();
    visited.resize(g.len(), false);

    q.push_back((source, 0));
    visited[source] = true;
    loop {
        let (i, depth) = match q.pop_front() {
            Some(x) => x,
            None => panic!("Path not found"),
        };
        if i == dest {
            return depth;
        }
        visited[i] = true;

        for child in &g[i] {
            if !visited[*child] {
                q.push_back((*child, depth+1));
            }
        }
    }
}

fn main() {
    let input = get_all_input();
    let m = unique_planets(&input.trim());

    /* Part 1 stuff 
    let g = get_graph(&input.trim(), &m);

    let dfsStartPoint = match m.get("COM") {
        Some(n) => *n,
        None => panic!("COM not found"),
    };

    println!("{}", count_dfs(&g, dfsStartPoint));
    */

    /* Part 2 stuff */
    let g = get_graph_part2(&input.trim(), &m);

    let youPos = match m.get("YOU") {
        Some(n) => *n,
        None => panic!("YOU not found"),
    };

    let sanPos = match m.get("SAN") {
        Some(n) => *n,
        None => panic!("SAN not found"),
    };

    println!("{}", count_bfs(&g, youPos, sanPos)-2);
}

