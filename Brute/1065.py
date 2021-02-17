import sys
input = sys.stdin.readline

N = int(input())
result = 0
num = [0 for i in range(3)]

if(N < 100):
    result = N
else:
    result = 99
    for i in range(100, N+1):
        num[0] = int(i / 100)
        num[1] = int((i % 100) / 10)
        num[2] = int((i % 100) % 10)
        if (num[0] - num[1]) == (num[1] - num[2]):
            result = result + 1

print(result)