import sys
input = sys.stdin.readline

N = int(input())

glass = [0 for i in range(N+1)]
dp = [0 for i in range(N+1)]

for i in range(1, N+1):
    glass[i] = int(input())

dp[1] = glass[1]
if N >= 2:
    dp[2] = dp[1] + glass[2]
    
    for i in range(3, N+1):
        dp[i] = max(dp[i-3] + glass[i-1] + glass[i], dp[i-2] + glass[i], dp[i-1])
        
print(max(dp))

'''
기존 계단 문제에서 이전가지의 최대 + 현재 와인을 마시지 않는 경우도 추가해서 max를 해주어야 함.

계단문제에서는 무조건 1칸 or 2칸만 올라갈수 있었지만 
와인잔 문제에서는 다음잔을 먹어야한다는 조건이 없음
 -> 2잔이상을 건너뛰고 마실 수 도 있음.
 9잔, 6 10 13 9 8 1 1 2 4
 라는 데이터가 들어오게 되면
 
 뒤에 1 1 을 마시지 않고 2 4 를 마심으로써 극대화 시킬 수 있음.
'''