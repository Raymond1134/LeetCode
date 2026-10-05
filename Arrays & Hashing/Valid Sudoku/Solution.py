from collections import defaultdict

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = defaultdict(list)
        cols = defaultdict(list)
        squares = defaultdict(list)

        for r, row in enumerate(board):
            for c, num in enumerate(row):
                if num == '.':
                    continue
                if num in rows[r] or num in cols[c] or num in squares[(r // 3) * 3 + (c // 3)]:
                    return False
                rows[r].append(num)
                cols[c].append(num)
                squares[(r // 3) * 3 + (c // 3)].append(num)
        
        return True
