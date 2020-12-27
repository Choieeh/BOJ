import sys
input = sys.stdin.readline

N = int(input())

DP = [0 for i in range(N+1)]

DP[1] = 1

if N >= 2:
    DP[2] = 1
    for i in range(3, N+1):
        DP[i] = DP[i-1] + DP[i-2]

print(DP[N])