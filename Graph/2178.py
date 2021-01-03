import sys
input = sys.stdin.readline


def bfs(n, m):
    queue = []
    queue.append([n, m])
    while queue:
        a = queue.pop(0)
        x = a[0]
        y = a[1]
        for dx, dy in (1,0), (-1,0),(0,1),(0,-1):
            if 0 <= x+dx < N and 0 <= y+dy < M and matrix[x+dx][y+dy] ==1:
                queue.append([x+dx, y+dy])
                matrix[x+dx][y+dy] = matrix[x+dx][y+dy] + matrix[x][y]

            
N, M = map(int, input().split())

matrix = [0 for i in range(N)]
visited = [[0 for i in range(M)] for j in range(N)]

for i in range(N):
    matrix[i] = input()
    matrix[i] = list(matrix[i].rstrip())
    matrix[i] = list(map(int, matrix[i]))
    

bfs(0, 0)
print(matrix[N-1][M-1])
print(matrix)


'''
dfs로 해결하려고 했으나 dfs로 하면 최단거리가 아닐수도 있음
bfs사용해서 풀어야함.

'''