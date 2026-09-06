class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = [[] for _ in range(numCourses)]
        degrees = [0] * numCourses

        for a, b in prerequisites:
            graph[b].append(a)
            degrees[a] += 1
        
        degreeZeroNodes = []

        for i in range(numCourses):
            if degrees[i] == 0: degreeZeroNodes.append(i)
        
        while degreeZeroNodes:
            node = degreeZeroNodes.pop()

            for neighbour in graph[node]:
                degrees[neighbour] -= 1
                if degrees[neighbour] == 0: degreeZeroNodes.append(neighbour)
        
        return all(degree == 0 for degree in degrees)