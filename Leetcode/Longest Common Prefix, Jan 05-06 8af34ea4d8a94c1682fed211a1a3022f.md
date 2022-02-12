# Longest Common Prefix, Jan 05-06

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

**Example 1:**

```
Input: strs = ["flower","flow","flight"]
Output: "fl"

```

**Example 2:**

```
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

```

**Constraints:**

- `1 <= strs.length <= 200`
- `0 <= strs[i].length <= 200`
- `strs[i]` consists of only lower-case English letters.

My solution:

Runtime: 59 ms, faster than 8.76% of Python3 online submissions for Longest Common Prefix.
Memory Usage: 14.5 MB, less than 24.98% of Python3 online submissions for Longest Common Prefix.

```python
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        min_len = min([len(i) for i in strs])
        sums={}
        
        for i in range(min_len+1):
            f=strs[0][0:i]
            idx=0
            for j in strs:
                if f == j[0:i]:
                    idx+=1
                    sums[f] = idx
        sums = {k: v for k, v in sums.items() if v==len(strs)}
        return(list(sums)[-1])
```

Other people’s solution: - similar but more simple

```python

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        min_len = min([len(i) for i in strs])
        sums={}
        
        for i in range(min_len+1):
            f=strs[0][0:i]
            idx=0
            for j in strs:
                if f == j[0:i]:
                    idx+=1
                    sums[f] = idx
        sums = {k: v for k, v in sums.items() if v==len(strs)}
        return(list(sums)[-1])

```

Other people’s solution2: this uses zip(*) → iterable tuple

```python
class Solution:
    # @return a string
    def longestCommonPrefix(self, strs):
        if not strs:
            return ""
            
        for i, letter_group in enumerate(zip(*strs)):
            if len(set(letter_group)) > 1:
                return strs[0][:i]
        else:
            return min(strs)
```