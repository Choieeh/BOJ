N = int(input())

A = [[0 for x in range(2)] for y in range(N+1)]
S = [0 for i in range(N+2)]

for i in range(1, N+1):
    A[i][0], A[i][1] = input().split()
    A[i][0] = int(A[i][0])
    A[i][1] = int(A[i][1])

for i in range(1, N+2):
    if i + A[i][0] <= N+1:
        S[i+A[i][0]] = max(S[i+A[i][0]], S[i] + A[i][1])
    if i < N:
        S[i+1] = max(S[i], S[i+1])

print(S[N+1])
            
'''
1 2 3 4 5 6 7
3 5 1 A 2 4 2
0 0 0 0 15 40 200
3 6 3 4 6 9 8
0 0 10 30 30 
'''