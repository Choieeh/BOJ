import sys
input = sys.stdin.readline
num = 8

def check_right(start, direction):
    if start > 4 or meet[start-1] == 1:
        return
    
    if meet[start-1] == -1:
        check_right(start+1, -direction)
        if direction == 1:
            temp = tob.pop()
            tob.insert(0, temp)
        else:
            temp = tob.pop(0)
            tob.append(temp)

def check_left(start, direction):
    if start < 1 or meet[start] == 1:
        return
    
    if meet[start] == -1:
        check_left(start-1, -direction)
        if direction == 1:
            temp = tob.pop()
            tob.insert(0, temp)
        else:
            temp = tob.pop(0)
            tob.append(temp)

tob = [0 for i in range(5)]
meet = [0 for i in range(4)]
result = 0

for i in range(1, 5):
    tempt = input()
    tob[i] = list(map(int, str(tempt)))

K = int(input())
print(tob)
turn = [0 for i in range(K)]
for i in range(K):
    turn[i] = list(map(int, input().split()))

for i in range(K):
    t_num = turn[i][0]
    direction = turn[i][1]
    
    check_right(t_num+1, direction)
    check_left(t_num-1, direction)
    
    if direction == 1:
        temp = tob.pop()
        tob.insert(0, temp)
    else:
        temp = tob.pop(0)
        tob.append(temp)

result = tob[1][0]*1 + tob[2][0]*2 + tob[3][0]*4 + tob[4][0] * 8

print(result)

#1번 2 <-> 2번 6 2번 2 <-> 3번 6 3번 2 <-> 4번 6