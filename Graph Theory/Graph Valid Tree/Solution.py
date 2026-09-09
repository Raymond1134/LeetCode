class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        graph = [[] for i in range(n)]

        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)
        
        visited = set()
        stack = [(0, -1)]

        while stack:
            node, parent = stack.pop()
            if node in visited: return False
            visited.add(node)

            for neighbour in graph[node]:
                if neighbour != parent: stack.append((neighbour, node))
        
        return len(visited) == n