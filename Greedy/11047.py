import sys
input = sys.stdin.readline

N, K = map(int, input().split())
count = 0
t = 0
A = [0 for i in range(N+1)]
for i in range(1, N+1):
    temp = int(input())
    if temp > K:
        continue
    else:
        A[i] = temp
        t = t+1

for i in range(t, 0, -1):
    if K == 0:
        break
    if K//A[i] > 0:
        count += K//A[i]
        K = K - (K//A[i]) * A[i]
    
print(count)

'''
처음엔 하나씩 빼는 방법을 했지만
나눈 몫을 count에 더하는 방법으로 해야 시간 초과가 뜨지 않는다.
'''
