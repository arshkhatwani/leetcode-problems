from typing import List
from collections import defaultdict

'''
- Any node arriving to a node i.e. already safe or terminal node is safe
- Any node that has 0 outdegree is both a terminal node and safe node
- Any node that arrives to itself or an unsafe node or a visited node is unsafe
- We can use dictionary to keep track of safe and unsafe nodes
- If a node is unsafe then all the nodes in the current traversal path are unsafe too
'''

class Solution:
    def eventualSafeNodes(self, adj: List[List[int]]) -> List[int]:
        n = len(adj)
        safe = defaultdict(bool)
        unsafe = defaultdict(bool)
        visited = [0 for i in range(n)]

        def dfs(src: int) -> bool:
            if src in safe:
                return True
            if visited[src] or src in unsafe:
                return False

            visited[src] = 1
            for node in adj[src]:
                if not dfs(node):
                    unsafe[src] = True
                    return False

            safe[src] = True
            return True

        for node in range(0, n):
            dfs(node)

        safeNodes = [node for node in safe]
        safeNodes.sort()

        return safeNodes
