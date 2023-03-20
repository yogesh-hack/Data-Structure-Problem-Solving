# problem : 242

# Input: s = "anagram", t = "nagaram"
# Output: true

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        sc = Counter(s)
        tc = Counter(t)
        if(sc == tc):
            return True
        return False
