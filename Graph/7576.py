import sys
input = sys.stdin.readline

def bfs(x, y):
    q = []
    q.append([x, y])
    while q:
        a = q.pop(0)
        x = a[0]
        y = a[1]
        for dx, dy in (1,0), (-1,0),(0,1),(0,-1):
            if 0 <= x + dx < M and 0 <= y + dy < N and matrix[x+dx][y+dy] == 0:
                matrix[x+dx][y+dy] = matrix[x][y] + 1
                q.append([x+dx, y+dy])
    

M, N = map(int,input().split())

matrix = [0 for i in range(N)]

for i in range(N):
    matrix[i] = list(map(int, input().split()))

for i in range(N):
    for j in range(M):
        if matrix[i][j] == 1:
            q = bfs(i, j)

for i in range(N):
    for j in range(M):
        if matrix[i][j] == 0:
            res = -1

            
if res == -1:
    result = -1
elif res 
print(matrix)
