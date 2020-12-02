n = int(input())

stair = [0 for i in range(n+1)]
for i in range(1, n+1):
    stair[i] = int(input())

count = 0
#count++해서 3이면 이단으로 건너뛰기