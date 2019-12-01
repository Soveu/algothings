use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut m: HashMap<i32, i32> = HashMap::new();
        
        for i in 0..nums.len() {
            let toFind = target - nums[i];
            match m.get(&toFind) {
                Some(j) => { return vec![i as i32, *j as i32]; },
                None => { m.insert(nums[i], i as i32); },
            }
        }
        
        return vec![-1, -1];
    }
}

