import sys
input = sys.stdin.readline

N = int(input())

house = [[0 for i in range(3)] for j in range(N)]
for i in range(N):
    house[i][0], house[i][1], house[i][2] = map(int, input().split())

cost = [[0 for i in range(3)] for j in range(N)]
cost[0] = house[0]

for i in range(1, N-1):
    cost[i][0] = min(cost[i-1][1], cost[i-1][2]) + house[i][0]
    cost[i][1] = min(cost[i-1][0], cost[i-1][2]) + house[i][1]
    cost[i][2] = min(cost[i-1][0], cost[i-1][1]) + house[i][2]

cost[N-1][0] = min(cost[N-2][1], cost[N-2][2]) + house[N-1][0]
cost[N-1][1] = min(cost[N-2][0], cost[N-2][2]) + house[N-1][1]
cost[N-1][2] = min(cost[N-2][0], cost[N-2][1]) + house[N-1][2]

print(min(cost[N-1][0], cost[N-1][1], cost[N-1][2]))