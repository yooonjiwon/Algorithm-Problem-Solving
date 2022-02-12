# Palindrome Number, Dec 31,2021-Jan 01, 2021

Given an integer `x`, return `true` if `x` is palindrome integer.

An integer is a **palindrome** when it reads the same backward as forward.

- For example, `121` is a palindrome while `123` is not.

**Example 1:**

```
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

```

**Example 2:**

```
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

```

**Example 3:**

```
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

```

**Constraints:**

- `231 <= x <= 231 - 1`

My Solution (I couldn’t solve without converting integer to string):

```python
class Solution:
    def isPalindrome(self, x: int) -> bool:
        # if x<0:
        #     return False
        # elif x<10:
        #     return True
        # else:
        x=str(x)
        if x[0:len(x)//2]==x[::-1][0:len(x)//2]:
            return True
        else:
            return False
```

Other People’s Solution (This code didn’t convert integer to string):

```python
def isPalindrome(self, x: int) -> bool:
	if x < 0 or (x > 0 and x%10 == 0):   # if x is negative, return False. if x is positive and last digit is 0, that also cannot form a palindrome, return False.
		return False
	
	result = 0
	while x > result:
		result = result * 10 + x % 10
		x = x // 10
		
	return True if (x == result or x == result // 10) else False
```