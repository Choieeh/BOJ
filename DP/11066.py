import sys
input = sys.stdin.readline
T = int(input())

for t in range(T):
    count = 0
    N = int(input())
    size = [int(x) for x in input().split()]
    dp = [[0 for i in range(N+1)] for j in range(N+1)]
    
    for i in range(1, N):
        dp[i][i+1] = size[i-1] + size[i]
        print(dp)

    for i in range(1, N+1):
        for j in range(1, N+1):
            dp[i][j] = 
    
'''
경우의 수를 따지는 다른 접근이 필요할듯.
'''