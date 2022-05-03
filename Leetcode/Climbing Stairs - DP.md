# Climbing Stairs - DP

You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?

**Example 1:**

```
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

```

**Example 2:**

```
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```

My solution:

```python
from math import comb

class Solution:
    def climbStairs(self, n: int) -> int:

        n_ = n//2 +1
        s = 0
        for i in range(n_):
            s+=comb(n,i)
            n-=1
        return(s)
```

Let’s say n=6.

- In case we have 0 number of 2: 6C0=1
1,1,1,1,1,1
- In case we have 1 number of 2: 5C1=5
2,1,1,1,1
1,2,1,1,1
1,1,2,1,1
1,1,1,2,1
1,1,1,1,2
- In case we have 2 number of 2: 4C2=6
1,2,1,2
1,1,2,2
2,2,1,1
1,2,2,1
2,1,1,2
2,1,2,1
- In case we have 3 number of 2: 3C3=1
2,2,2

The result is the sum of 6C0+5C1+4C2+3C3=13

**Others’ solution**:

Most of the people solved this problem with dynamic programming.

```python
def climb(n):
    #edge cases
    if n==0: return 0
    if n==1: return 1
    if n==2: return 2
    dp = [0]*(n+1) # considering zero steps we need n+1 places
    dp[1]= 1
    dp[2] = 2
    for i in range(3,n+1):
        dp[i] = dp[i-1] +dp[i-2]
    print(dp)
    return dp[n]
```

**Dynamic Programming (DP):**

DP is approach to solve problem efficiently by dividing into subproblems. One of the well-known example is Fibonacci.