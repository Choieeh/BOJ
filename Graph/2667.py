import sys
input = sys.stdin.readline

matrix = [0 for i in range(N)]

N = int(input())

for i in range(N):
    matrix[i] = input()
    matrix[i] = list(matrix[i].rstrip())
    matrix[i] = list(map(int, matrix[i]))