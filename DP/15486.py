import sys

N = int(input())

A = [[0 for x in range(2)] for y in range(N+1)]
S = [0 for i in range(N+2)]

for i in range(1, N+1):
    A[i][0], A[i][1] = sys.stdin.readline().split()
    #input은 속도가 느림.
    A[i][0] = int(A[i][0])
    A[i][1] = int(A[i][1])

for i in range(1, N+1):
    if i + A[i][0] <= N+1:
        S[i+A[i][0]] = max(S[i+A[i][0]], S[i] + A[i][1])
    S[i+1] = max(S[i], S[i+1])

print(S[N+1])
            
'''
입출력 속도가 sys.stdin.readline() > raw_input() > input() 순으로 빨라서 input을 사용하면 시간초과가 되는것.
'''