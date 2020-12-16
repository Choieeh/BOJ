import sys

M, N = sys.stdin.readline().split()
M = int(M)
N = int(N)

table = [[0 for i in range(N)] for j in range(M)]
dp = [[0 for i in range(N)] for j in range(M)]

for i in range(M):
    table[i] = [int(x) for x in input().split()]

dp[0][0] = 1
'''
for i in range(M):
    for j in range(N):
        if i-1>=0 and table[i][j] < table[i-1][j]:
            dp[i][j] = dp[i][j] + dp[i-1][j]
        if j-1>=0 and table[i][j] < table[i][j-1]:
            dp[i][j] = dp[i][j] + dp[i][j-1]
        if j+1<N and table[i][j] < table[i][j+1]:
            dp[i][j] = dp[i][j] + dp[i][j+1]
        if i+1<M and table[i][j] < table[i+1][j]:
            dp[i][j] = dp[i][j] + dp[i+1][j]
'''
for i in range(M):
    for j in range(N):
        if i-1>=0 and table[i][j] > table[i-1][j]:
            dp[i-1][j] = dp[i][j] + dp[i-1][j]
        if j-1>=0 and table[i][j] > table[i][j-1]:
            dp[i][j-1] = dp[i][j] + dp[i][j-1]
        if j+1<N and table[i][j] > table[i][j+1]:
            dp[i][j+1] = dp[i][j] + dp[i][j+1]
        if i+1<M and table[i][j] > table[i+1][j]:
            dp[i+1][j] = dp[i][j] + dp[i+1][j]
            
print(dp)
print(dp[M-1][N-1])

'''
dp 만을 사용하여 풀려했으나
dp + dfs 로 풀어야 하는 문제.
dfs를 까먹어서 다시 공부하고 풀어야할 것 같다.
'''