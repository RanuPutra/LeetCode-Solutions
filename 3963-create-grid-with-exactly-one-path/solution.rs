pub struct Solution;

impl Solution {
    pub fn create_grid(m: i32, n: i32) -> Vec<String> {
        let m = m as usize;
        let n = n as usize;
        let mut grid = Vec::with_capacity(m);

        for i in 0..m {
            if i == 0 {
                grid.push(".".repeat(n));
            } else {
                let mut row = "#".repeat(n - 1);
                row.push('.');
                grid.push(row);
            }
        }

        grid
    }
}
