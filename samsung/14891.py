import sys
input = sys.stdin.readline
num = 8

tob = [0 for i in range(5)]
meet = [0 for i in range(4)]

for i in range(1, 5):
    tob[i] = list(map(int, input().split()))

K = int(input())

turn = [0 for i in range(K)]
for i in range(K):
    turn[i] = list(map(int, input().split()))

for i in range(K):
    t_num = turn[i][0]
    direction = turn[i][1]
    
    for j in range(1, 4):
        if tob[j][2] == tob[j+1][6]:
            meet[j] = 1
        else:
            meet[j] = -1
        
    if t_num == 1:
        for k in range(1, 4):
            if meet[k] == 1:
                
    else if t_num == 2 or t_num == 3:
        
    else:
        


#1번 2 <-> 2번 6 2번 2 <-> 3번 6 3번 2 <-> 4번 6