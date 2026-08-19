class Solution:
    def minWindow(self, s: str, t: str) -> str:
        unsatisfied = 0
        requiredChars = {}
        windowChars = {}
        left, right = 0, -1
        lastIndex = len(s) - 1
        currMaxLength = len(s) + 1
        currString = ""

        if len(t) > len(s): return ""

        for char in t:
            if char in requiredChars.keys():
                requiredChars[char] += 1
            else:
                unsatisfied += 1
                requiredChars[char] = 1
        
        while True:
            if unsatisfied > 0:
                if right == len(s) - 1: break
                right += 1
                windowChars[s[right]] = windowChars.get(s[right], 0) + 1
                if windowChars[s[right]] == requiredChars.get(s[right], 0): unsatisfied -= 1
            else:
                if windowChars[s[left]] == requiredChars.get(s[left], 0): unsatisfied += 1
                windowChars[s[left]] = windowChars.get(s[left], 0) - 1
                left += 1
            
            if unsatisfied == 0 and right - left + 1 < currMaxLength:
                currString = s[left:right + 1]
                currMaxLength = right - left + 1
        
        return currString
