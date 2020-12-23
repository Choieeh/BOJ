import copy
import sys
input = sys.stdin.readline

N = int(input())

table = [0 for i in range(N+1)]
for i in range(1, N+1):
    table[i] = list(map(int, input().split()))

DP = copy.deepcopy(table)

for i in range(1, N):
    for j in range(i):
        DP[i+1][j] = max(table[i+1][j] + DP[i][j], DP[i+1][j])
        DP[i+1][j+1] = max(table[i+1][j+1] + DP[i][j], DP[i+1][j+1])
        
print(max(DP[N]))

'''
list를 복사할떄는 얕은복사, 깊은 복사가 있는데
얕은 복사를 하게되면 reference만 참조하게 되어
data를 수정하면 내용이 같이 바뀌게 됨
copy module을 import해서 copy.deepcopy를 사용해야 깊은 복사(내용 완전 복사)가 가능함.

max(list) 를 하면 list에서 가장 큰 값이 반환됨.
'''