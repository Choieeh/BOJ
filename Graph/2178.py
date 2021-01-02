import sys
input = sys.stdin.readline

N, M = map(int, input().split())

matrix = [0 for i in range(N)]

for i in range(N):
    matrix[i] = input()
    matrix[i] = list(matrix[i])
    
    
print(matrix)