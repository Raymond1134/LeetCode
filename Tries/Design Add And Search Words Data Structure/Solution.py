class WordDictionary:
    class Node:
        def __init__(self):
            self.children = {}
            self.is_end = False

    def __init__(self):
        self.root = self.Node()

    def addWord(self, word: str) -> None:
        curr = self.root
        for char in word:
            if char not in curr.children: curr.children[char] = self.Node()
            curr = curr.children[char]
        curr.is_end = True

    def search(self, word: str) -> bool:
        def dfs(start, idx):
            curr = start
            for i in range (idx, len(word)):
                if word[i] == '.':
                    return any(dfs(child, i + 1) for child in curr.children.values())
                if word[i] not in curr.children: return False
                curr = curr.children[word[i]]
            return curr.is_end
        return dfs(self.root, 0)
