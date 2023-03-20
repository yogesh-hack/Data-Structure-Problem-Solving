# problem : 383

# Input: ransomNote = "aa", magazine = "aab"
# Output: true

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        # Create a hash table to keep track of the frequency of each character in the magazine string
        freq = {}
        for c in magazine:
            freq[c] = freq.get(c, 0) + 1

        # Iterate through the ransomNote string and check if each character is present in the hash table
        # and if its frequency is greater than zero
        for c in ransomNote:
            if c not in freq or freq[c] == 0:
                return False
            freq[c] -= 1

        # If we reach here, all the characters in the ransomNote string have been found in the magazine string
        return True
            
