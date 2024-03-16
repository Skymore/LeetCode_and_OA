class UnionFind:
    def __init__(self, size):
        self.root = [i for i in range(size)]
        self.rank = [1] * size

    def find(self, x):
        if x == self.root[x]:
            return x
        self.root[x] = self.find(self.root[x]) #Path Compression
        return self.root[x]
    
    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)

        if rootX != rootY:
            if self.rank[rootX] > self.rank[rootY]:
                self.root[rootY] = rootX
            elif self.rank[rootX] < self.rank[rootY]:
                self.root[rootX] = rootY
            else:
                self.root[rootY] = rootX
                self.rank[rootX] += 1
    
    def connected(self, x, y):
        return self.find(x) == self.find(y)

# main

if __name__ == "__main__":
    n, m, q = map(int, input().split())

    lines = [list(map(int, input().split())) for _ in range(m)]
    queries = [list(map(int, input().split())) for _ in range(q)]

    nodes = set()
    for u, v in lines:
        nodes.add(u)
        nodes.add(v)
    for _, u, v in queries:
        nodes.add(u)
        nodes.add(v)
    
    sorted_nodes = sorted(list(nodes))
    node_id = {node: i for i, node in enumerate(sorted_nodes)}
    n = len(nodes)

    uf = UnionFind(n)
    edges = set()

    # add edges and delete edges
    for u, v in lines:
        edges.add(frozenset([node_id[u], node_id[v]]))
        
    for op, u, v in queries:
        if op == 1:
            edges.discard(frozenset([node_id[u], node_id[v]]))


    # union
    for u, v in edges:
        uf.union(u, v) 
    


    ans = []
    # reverse queries
    for op, u, v in queries[::-1]:
        if op == 1:
            uf.union(node_id[u], node_id[v])
        else:
                #print root
            if uf.connected(node_id[u], node_id[v]):
                ans.append("Yes")
            else:
                ans.append("No")
    
    for a in ans[::-1]:
        print(a)
    
# Time Complexity: O(n + m + q)
# input
'''
5 3 5
1 2
2 3
4 5
1 1 5
2 1 3
2 1 4
1 1 2
2 1 3
'''