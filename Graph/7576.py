import sys
from collections import deque
input = sys.stdin.readline


def bfs():
    while q:
        a = q.popleft()
        x = a[0]
        y = a[1]
        for dx, dy in (1,0), (-1,0),(0,1),(0,-1):
            if 0 <= x + dx < N and 0 <= y + dy < M and matrix[x+dx][y+dy] == 0:
                matrix[x+dx][y+dy] = matrix[x][y] + 1
                q.append([x+dx, y+dy])
    

M, N = map(int,input().split())

matrix = [0 for i in range(N)]
q = deque()
for i in range(N):
    matrix[i] = list(map(int, input().split()))

for i in range(N):
    for j in range(M):
        if matrix[i][j] == 1:
            q.append([i, j])
        
bfs()
result = max(map(max, matrix)) - 1
            
for i in range(N):
    for j in range(M):
        if matrix[i][j] == 0:
            result = -1


print(result)
