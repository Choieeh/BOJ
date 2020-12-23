import sys
input = sys.stdin.readline

N = int(input())
matrix = [[0 for i in range(2)] for j in range(N)]
for i in range(N):
    matrix[i][0], matrix[i][1] = map(int, input().split())

'''
matrix
'''
