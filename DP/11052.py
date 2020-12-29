import sys
input = sys.stdin.readline

N = int(input())
dp = [0 for i in range(N+1)]

P = list(map(int, input().split()))
P = [0] + P

for i in range(1, N+1):
    for j in range(1, i+1):
        dp[i] = max(dp[i], P[j] + dp[i-j])
print(dp[N])