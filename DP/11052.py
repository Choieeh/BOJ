import sys
input = sys.stdin.readline

N = int(input())
P = [0 for i in range(N+1)]
dp = [[0 for i in range(N+1)] for j in range(N+1)]

for i in range(1, N+1):
    P[i] = int(input())

dp[1] = 
    
def makes(k):
    for i in range(k+1) :
        j = k - i
        dp[k] = max(dp[k], dp[i] + dp[j])
    
for i in range(1, N+1):
    for j in range(1, N+1):
        
        
        i+j = N
        dp[N] = max(dp[N], dp[i] + dp[j])