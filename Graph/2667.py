import sys
input = sys.stdin.readline

count = 0
num = 0

def dfs(x, y):
    global count
    matrix[x][y] = 2
    count = count + 1
    for dx, dy in (1,0), (-1,0),(0,1),(0,-1):
        if 0 <= x + dx < N and 0 <= y + dy < N and matrix[x+dx][y+dy] == 1:
            dfs(x+dx, y+dy)
    return matrix[x][y]

N = int(input())

matrix = [0 for i in range(N)]
answer = []

for i in range(N):
    matrix[i] = input()
    matrix[i] = list(matrix[i].rstrip())
    matrix[i] = list(map(int, matrix[i]))
    
for i in range(N):
    for j in range(N):
        count = 0
        if matrix[i][j] == 1:
            num = num + 1
            dfs(i, j)
            answer.append(count)

answer.sort()
print(num)
for i in range(num):
    print(answer[i])