import sys
input = sys.stdin.readline


def dfs(x, y):
    visited[x][y] = 1
    count = count+1
    if 
    for i in range(1, N+1):
        if visited[v][i] == 0 and matrix[v][i] == 1:
            dfs()
            
            
N, M = map(int, input().split())

matrix = [0 for i in range(N)]
visited = [[0 for i in range(M)] for j in range(N)]
count = 0

for i in range(N):
    matrix[i] = input()
    matrix[i] = list(matrix[i].rstrip())
    matrix[i] = list(map(int, matrix[i]))
    

print(matrix)