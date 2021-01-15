import sys
input = sys.stdin.readline

def dfs(v):
    global count
    visited[v] = 1
    count = count + 1
    for i in range(1, N+1):
        if visited[i] == 0 and line[v][i] == 1:
            dfs(i)


N = int(input())
D = int(input())

line = [[0 for i in range(N+1)] for j in range(N+1)]
visited = [0 for i in range(N+1)]

count = 0

for i in range(D):
    a, b = map(int, input().split())
    line[a][b] = 1
    line[b][a] = 1

dfs(1)
print(count-1)