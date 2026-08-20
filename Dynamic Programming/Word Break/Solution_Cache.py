from functools import cache
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        @cache
        def wordBreakMemo(s):
            if s == "": return True
            return any(s.startswith(word) and wordBreakMemo(s[len(word):]) for word in wordDict)
        
        return wordBreakMemo(s)