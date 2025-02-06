from collections import defaultdict
from typing import List

'''
- Sort the tickets to ensure we get smallest lexical path
- Here we need to traverse in such a way that all the edges are used up (edges = tickets)
- We use a stack for traversal and for every neighbor we add it to the stack and remove it from the adj list
- And if a node does not have any neighbors we add that node to the path and pop it out of the stack
- After iteration we will have the path in reverse format so we reverse it and return it as answer
'''

class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        tickets.sort()
        adj = defaultdict(list)

        for src, dest in tickets:
            adj[src].append(dest)

        stack = ["JFK"]
        path = []
        while stack:
            node = stack[-1]
            if not adj[node]:
                path.append(node)
                stack.pop()
            else:
                nei = adj[node][0]
                stack.append(nei)
                adj[node].pop(0)

        path.reverse()
        return path
