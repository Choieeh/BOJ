import sys

T = int(sys.stdin.readline())

for t in range(T):
    count = 0
    temp = 0
    N = sys.stdin.readline()
    size = [int(x) for x in input().split()]
    size.sort()
    ss = size
    while len(ss) == 1:
        temp = ss[0] + ss[1]
        del ss[:2]
        count = count + temp
        ss.append(temp)
    print(count)