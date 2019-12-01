extern crate rand;
use rand::Rng;

impl Solution {
    pub fn repeated_n_times(a: Vec<i32>) -> i32 {
        let mut rng = rand::thread_rng();
        let mut last = rng.gen_range(0, a.len());
        let mut next = rng.gen_range(0, a.len());
        
        while(last == next || a[last] != a[next]) {
            last = rng.gen_range(0, a.len());
            next = rng.gen_range(0, a.len());
        }
        
        return a[next];
    }
}

