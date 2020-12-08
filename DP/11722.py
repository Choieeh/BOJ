N = int(input())
count = 0
maxc = 0
curc = 0
mina = 0
A = [0 for i in range(N)]
B = [1 for i in range(N)]
Am = input().split()
A = list(map(int, Am))
#map은 리스트의 요소를 지정된 함수로 처리해 주는 함수(원본을 변경하지 않고 새 리스트를 생성)
'''
B[0] = 1
maxc = A[0]
curc = A[0]
for i in range(1, N):
    if A[i] > maxc:
        B[i] = 1
        maxc = A[i]
        curc = A[i]
    elif A[i] < curc:
        B[i] = B[i-1]+1
        curc = A[i]
    elif A[i] > curc and A[i] < maxc:
        
    else:
        B[i] = B[i-1]

ans = 0
for i in range(0, N):
    if ans < B[i]:
        ans = B[i]

print(ans)
난 여기서 다음에 오는 값이 max보단 작지만 cur보다 큰 경우를 예외 시키지 못함.
검색 - > 이전에 자기보다 큰수 파악후 그 개수를 통해 파악
'''

for i in range(1, N):
    for j in range(0, i):
        if A[i] < A[j] and B[j] + 1 > B[i]:
            B[i] = B[j] + 1
        elif A[i] == A[j]:
            B[i] = B[j]

ans = 0
for i in range(0, N):
    if ans < B[i]:
        ans = B[i]
print(ans)
#DP(다이나믹 프로그래밍)에서 중요한 것은 규칙을 찾거나, 어떤 일반식을 찾는 것이 키 포인트이다.