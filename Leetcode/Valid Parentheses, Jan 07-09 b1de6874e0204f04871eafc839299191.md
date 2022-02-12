# Valid Parentheses, Jan 07-09

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

**Example 1:**

```
Input: s = "()"
Output: true

```

**Example 2:**

```
Input: s = "()[]{}"
Output: true

```

**Example 3:**

```
Input: s = "(]"
Output: false

```

**Constraints:**

- `1 <= s.length <= 104`
- `s` consists of parentheses only `'()[]{}'`.

My solution: I tried to do stack.

```python
class Solution:
    def isValid(self, s: str) -> bool:

        par2 = [')','}',']']
        par_ = ('()','{}','[]')
        ans=''

        if s[0] in par2:
            return(False)
        else:
            for i in s:
                ans+=i
                if ans.endswith(par_):
                    ans=ans.replace('()','')
                    ans=ans.replace('{}','')
                    ans=ans.replace('[]','')
                print(ans)

        if ans == '':
            return(True)
        else:
            return(False)
```

Other people’s solution:

```python
class Solution(object):
	def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        d = {'(':')', '{':'}','[':']'}
        stack = []
        for i in s:
            if i in d:  # 1
                stack.append(i)
            elif len(stack) == 0 or d[stack.pop()] != i:  # 2
                return False
        return len(stack) == 0 # 3

# 1. if it's the left bracket then we append it to the stack
# 2. else if it's the right bracket and the stack is empty(meaning no matching left bracket), or the left bracket doesn't match
# 3. finally check if the stack still contains unmatched left bracket
```