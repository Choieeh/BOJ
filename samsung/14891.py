import sys
input = sys.stdin.readline
num = 8

def check_right(start, direction):
    print(start)
    if start > 4 or meet[start-1] == 1:
        return
    
    if meet[start-1] == -1:
        check_right(start+1, -direction)
        if direction == 1:
            temp = tob.pop()
            tob[start].insert(0, temp)
        else:
            temp = tob.pop(0)
            tob[start].append(temp)


def check_left(start, direction):
    if start < 1 or meet[start] == 1:
        return
    
    if meet[start] == -1:
        check_left(start-1, -direction)
        if direction == 1:
            temp = tob[start].pop()
            tob[start].insert(0, temp)
        else:
            temp = tob[start].pop(0)
            tob[start].append(temp)


tob = [0 for i in range(5)]
meet = [0 for i in range(4)]
result = 0

for i in range(1, 5):
    tempt = input().strip()
    tob[i] = list(map(int, str(tempt)))

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
    check_right(t_num+1, direction)
    check_left(t_num-1, direction)
    
    if direction == 1:
        temp = tob[t_num].pop()
        tob[t_num].insert(0, temp)
    else:
        temp = tob[t_num].pop(0)
        tob[t_num].append(temp)
print(meet)
print(tob)
result = tob[1][0]*1 + tob[2][0]*2 + tob[3][0]*4 + tob[4][0] * 8
print(tob[1][0], tob[2][0], tob[3][0], tob[4][0])
print(result)

#1번 2 <-> 2번 6 2번 2 <-> 3번 6 3번 2 <-> 4번 6