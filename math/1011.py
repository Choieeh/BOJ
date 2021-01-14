import sys
input = sys.stdin.readline

T = int(input())
case = [[0 for i in range(2)] for j in range(T)]

for i in range(T):
    x, y = map(int, input().split())
    c = y - x
    dp = [0 for i in range(c+1)]
    count = 1
    for j in range(1, c):
        dp[j] = count
        j = j +1
        dp[j+1] = count
        count = count + 1
        for k in range(2):
            
    
    1
    11
    111
    121
    1211
    1221
    12211
    12221
    12321
    123211
    123221
    123321
    1233211
    1233221
    1233321
    1234321
    1233445556667777888899999
    
    11223344
    1 = 1
    2 = 2
    3 = 3
    5 = 4
    123456789
    123344555
    