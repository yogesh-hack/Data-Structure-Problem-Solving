# problem : 387

# Input: s = "loveleetcode"
# Output: 2

class Solution:
    def firstUniqChar(self, s: str) -> int:
        char_dict = {}
        char_set = set()
        for i, c in enumerate(s):
            if c in char_set:
                if c in char_dict:
                    del char_dict[c]
            else:
                char_dict[c] = i
                char_set.add(c)
        if len(char_dict) == 0:
            return -1
        else:
            return min(char_dict.values())
        
