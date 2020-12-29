import sys
input = sys.stdin.readline


def dfs(v):
    visited[v] = 1
    print(v, end=' ')
    for i in range(1, N+1):
        if visited[i] == 0 and line[v][i] == 1:
            dfs(i)

def bfs(v):
    queue = [v]
    visited[v] = 1
    while queue:
        node = queue.pop(0)
        print(node, end=' ')
        for i in range(1, N+1):
            if visited[i] == 0 and line[node][i] == 1:
                queue.append(i)
                visited[i] = 1
            
N, M, V = map(int, input().split())

line = [[0 for i in range(N+1)] for j in range(N+1)]
visited = [0 for i in range(N+1)]

for i in range(M):
    x, y = map(int, input().split())
    line[x][y] = 1
    line[y][x] = 1

dfs(V)
visited = [0 for i in range(N+1)]
print()
bfs(V)