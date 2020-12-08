N = int(input())

A = [0 for i in range(N)]
B = [1 for i in range(N)]
A = input().split()
A = list(map(int, A))

for i in range(1, N):
    for j in range(0, i):
        if A[i] > A[j] and B[i] < B[j] + 1:
            B[i] = B[j] + 1

ans = 0
for i in range(0, N):
    if ans < B[i]:
        ans = B[i]

print(ans)