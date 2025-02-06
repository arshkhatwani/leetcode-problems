from typing import List

'''
Approach: DFS
1. Maintain a adjacency list
2. For every edge DFS from u,v. If DFS is possible then the edge is redundant
3. If DFS is not possible then the edge is not redundant and simply add the
nodes in adjacency list

Approach: DSU
1. Union every edge for every edges
2. Before union check if parent of u and v are same or not,
if they are same then we return [u, v] since this is an additional edge
'''

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        totalNodes = 1001
        visited = [0 for i in range(totalNodes)]
        adj = [[] for i in range(totalNodes)]

        def dfs(src, target):
            if visited[src]:
                return False
            if src == target:
                return True

            visited[src] = 1
            for node in adj[src]:
                if dfs(node, target):
                    return True

            return False

        ans = [-1, -1]
        for src, target in edges:
            visited = [0 for i in range(totalNodes)]
            if dfs(src, target):
                ans = [src, target]
            adj[src].append(target)
            adj[target].append(src)

        return ans

class DSU:
    def __init__(self, n: int):
        self.parent = [i for i in range(n + 1)]
        self.size = [1 for i in range(n + 1)]

    def findParent(self, x):
        if self.parent[x] == x:
            return x
        parent = self.findParent(self.parent[x])
        self.parent[x] = parent
        return parent

    def union(self, a: int, b: int):
        parentA = self.findParent(a)
        parentB = self.findParent(b)

        sizeA = self.size[parentA]
        sizeB = self.size[parentB]

        if sizeA >= sizeB:
            self.parent[parentB] = parentA
            self.size[parentA] += self.size[parentB]
        else:
            self.parent[parentA] = parentB
            self.size[parentB] += self.size[parentB]


class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        dsu = DSU(n)

        ans = []
        for u, v in edges:
            if dsu.findParent(u) == dsu.findParent(v):
                ans = [u, v]
                break
            dsu.union(u, v)

        return ans
