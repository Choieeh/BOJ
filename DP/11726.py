n = int(input())

ans = [0 for i in range(n+1)]

ans[1] = 1
if n >= 2:
    ans[2] = 2
    for i in range(3, n+1):
        ans[i] = ans[i-1]+ans[i-2]

print(ans[n] % 10007)
'''
1 2 3 5 8 13 21 34 55
'''