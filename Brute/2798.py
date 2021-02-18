import sys
input = sys.stdin.readline

N, M = map(int, input().split())
card = list(map(int, input().split()))
Nsum = 0
Max = 0

for i in range(N):
    for j in range(i+1, N):
        for k in range(j+1, N):
            Nsum = card[i] + card[j] + card[k]
            if(Nsum <= M and Nsum > Max):
                Max = Nsum

print(Max)