# Final exam algorithmic thinking course
This is our's solution for The Final exam of HCMUS - Algorithmic Thinking Course (CNTN 2020)
<!-- 
## Note
### Problem 1
- Build up a segment tree for quick calculating gcd of value in range `[i, j]` (0 <= i <= j < n).
- Interate over the list from 0 to [n - k - 1] and each step 
### Problem 2
- `2xn` is an even number, so `p` and `q` are odd primes (not include 2).  
- The problem becomes `p+q <= 2xn`.
- List all prime numbers greater than 3, for each `q` find number of `p` such that `p <= 2xn - q`.
- Using 2 pointers to solve in `O(N)`

### Problem 3
- Sort array `a` and `b`, for each elements in `a` find the element in `b` such that `|a + b|` is the smallest.
- Easy to observe that we need to find `b'` that `|a + b'|` is the nearest to zero
- There are 2 cases
  - `a + b' < 0` => `b' < -a` => find the largest `b' < -a`
  - `a + b' >= 0` => `b' >= -a` => find the smallest `b' >= -a`

### Problem 5
- Hasing (ez to explain)
  
### Problem 6
- Using min-heap instead, each node of min-heap stores {val, index}.
- Perform in `O(N * K * log K)` -->