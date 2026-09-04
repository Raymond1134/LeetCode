class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:

        def search(target, i, j, visited):
            if not target: return True

            nextChar = target[0]
            target = target[1:]

            if i > 0 and board[i - 1][j] == nextChar and (i - 1, j) not in visited:
                visited.append((i - 1, j))
                if search(target, i - 1, j, visited): return True
                visited.pop()

            if i < len(board) - 1 and board[i + 1][j] == nextChar and (i + 1, j) not in visited:
                visited.append((i + 1, j))
                if search(target, i + 1, j, visited): return True
                visited.pop()

            if j > 0 and board[i][j - 1] == nextChar and (i, j - 1) not in visited:
                visited.append((i, j - 1))
                if search(target, i, j - 1, visited): return True
                visited.pop()

            if j < len(board[0]) - 1 and board[i][j + 1] == nextChar and (i, j + 1) not in visited:
                visited.append((i, j + 1))
                if search(target, i, j + 1, visited): return True
                visited.pop()
            
            return False
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == word[0]:
                    if search(word[1:], i, j, [(i, j)]): return True
        
        return False

