# Sqrt(x) - Binary Search

[Problem](https://leetcode.com/problems/sqrtx/):

Given a non-negative integer `x`, compute and return *the square root of* `x`.

Since the return type is an integer, the decimal digits are **truncated**, and only **the integer part** of the result is returned.

**Note:** You are not allowed to use any built-in exponent function or operator, such as `pow(x, 0.5)` or `x ** 0.5`.

**Example 1:**

```
Input: x = 4
Output: 2

```

**Example 2:**

```
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
```

**Constraints:**

- `0 <= x <= 231 - 1`

**My solution**: I failed this challenge because of Time Limit. I didn’t know how to fix it,  so I checked others’ solution.

```python
class Solution:
    def mySqrt(self, x: int) -> int:

        i=0
        for j in range(x+1):
            if j==i*i:
                i+=1
            # else:
            #     pass
      
        return(i-1)
```

**Other’s solution**: This person used binary search (O(logn)). In my case I had to calculate all the way to x. But this solution calculated only the near of the x. It becomes much more faster than mine.

```python
class Solution:
    def mySqrt(self, x: int) -> int:

        l, r = 0, x
        while l <= r:
            mid = l + (r-l)//2
            if mid * mid <= x < (mid+1)*(mid+1):
                return mid
            elif x < mid * mid:
                r = mid - 1
            else:
                l = mid + 1
```

**Binary Search**:

Binary Search is one of the **search algorithm**, repeatedly narrowing down the searching area **in half** until there is nothing to search. 

The complexity is **O(logn)** as described in other’s solution. When we look at the above code, it is cut **in** **half (l + (r-1)//2)** **while l ≤ r.**