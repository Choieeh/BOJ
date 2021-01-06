import sys
input = sys.stdin.readline

M, N = map(int,input().split())

matrix = [0 for i in range(N)]

for i in range(N):
    matrix[i] = list(map(int, input().split()))

for i in range(N):
    for j in range(M):
        

print(matrix)