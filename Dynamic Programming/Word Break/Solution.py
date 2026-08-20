class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        def wordBreakMemo(s, memo):
            if s in memo.keys(): return memo[s]
            memo[s] = any(s.startswith(word) and wordBreakMemo(s[len(word):], memo) for word in wordDict)
            return memo[s]
        
        return wordBreakMemo(s, {"": True})