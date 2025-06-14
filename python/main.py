edges1 = [[0,1],[0,2],[2,3],[3,10],[2,4]]
vertex = set()
for u,v in edges1:
    vertex.add(u)
    vertex.add(v)
print(len(vertex))

g = [[] for _ in range(len(vertex))]
for u,v in edges1:
    g[u].append(v)

print(g)
def dfs(u):
    print(u)
    for v in g[u]:
        dfs(v)

if __name__ == '__main__':
    dfs(0)