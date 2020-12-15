import sys

M, N = sys.stdin.readline().split()
M = int(M)
N = int(N)

table = [[0 for i in range(N)] for j in range(M)]
dp = [[0 for i in range(N)] for j in range(M)]

for i in range(M):
    table[i] = [int(x) for x in input().split()]

dp[0][0] = 1
for i in range(M):
    for j in range(N):
        dp[i][j] = max(dp[i][j], dp[i-1][j] + dp[i][j-1] + dp[i][j+1] + dp[i+1][j])

print(dp[M-1][N-1])