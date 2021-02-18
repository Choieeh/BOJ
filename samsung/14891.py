import sys
input = sys.stdin.readline
num = 8

tob = [0 for i in range(5)]

for i in range(1, 5):
    tob[i] = list(map(int, input().split()))

K = int(input())

turn = [0 for i in range(K)]
for i in range(K):
    turn[i] = list(map(int, input().split()))

for i in range(K):
    t_num = turn[i][0]
    if t_num == 1:
        
    else if t_num == 2 or t_num == 3:
        
    else:
        


#1번 2 <-> 2번 6 2번 2 <-> 3번 6 3번 2 <-> 4번 6