class DisjointSet:
    def __init__(self, n):
        self.rank = [0 for _ in range(n)]
        self.parent = [i for i in range(n)]

    def find_parent(self, node):
        if node == self.parent[node]:
            return node
        
        self.parent[node] = self.find_parent(self.parent[node])
        return self.parent[node]
    
    def union_by_rank(self, u, v):
        parent_u = self.find_parent(u)
        parent_v = self.find_parent(v)

        if parent_u == parent_v:
            return False
        
        if self.rank[parent_u] < self.rank[parent_v]:
            self.parent[parent_u] = parent_v
        elif self.rank[parent_u] > self.rank[parent_v]:
            self.parent[parent_v] = parent_u
        else:
            self.rank[parent_u] += 1
            self.parent[parent_v] = parent_u
        
        return True

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        if len(points) <= 1:
            return 0

        #generate the (cost, u, v) list
        graph = self.create_graph(points)
        graph.sort(key=lambda x: x[0])

        n = len(points)
        ds = DisjointSet(n)

        result = 0
        count  = 0

        for i in graph:
            weight, vertex1, vertex2 = i

            #we need only n-1 edges to make a minimum spanning tree
            if count == n-1:
                break
            
            if ds.union_by_rank(vertex1, vertex2):
                result += weight
                count += 1
            else:
                continue
        
        return result
    
    def difference (self, x1, x2, y1, y2):
        return abs(x1 - x2) + abs(y1 - y2)

    def create_graph(self, points):
        graph = []

        for i in range(len(points) - 1):
            for j in range(i+1, len(points)):
                curr_point = points[i]
                next_point = points[j]
                weight = self.difference(curr_point[0], next_point[0], curr_point[1], next_point[1])

                graph.append((weight, i, j))
        
        return graph
        