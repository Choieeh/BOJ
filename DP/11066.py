import sys
input = sys.stdin.readline
T = int(input())

for t in range(T):
    count = 0
    temp = 0
    N = input()
    size = [int(x) for x in input().split()]
    size.sort()
    ss = size
    while len(ss) != 1:
        temp = ss[0] + ss[1]
        del ss[:2]
        count = count + temp
        ss.append(temp)
        ss.sort()
    print(count)
    
'''
경우의 수를 따지는 다른 접근이 필요할듯.
'''