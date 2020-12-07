N = int(input())
count = 0
maxc = 0
mina = 0
A = [0 for i in range(N)]

Am = input().split()
A = list(map(int, Am))
#map은 리스트의 요소를 지정된 함수로 처리해 주는 함수(원본을 변경하지 않고 새 리스트를 생성)

print(A)

for i in range(N):
    count = 0
    mina = A[i]
    for j in range(i, N):
        print(A[j])
        print(count)
        if A[j] > A[i]:
            i = j
            if count > maxc:
                maxc = count
            break
        elif A[j] < mina:
            count = count+1
            mina = A[j]
        if count > maxc:
            maxc = count
            
print(maxc)

#DP(다이나믹 프로그래밍)에서 중요한 것은 규칙을 찾거나, 어떤 일반식을 찾는 것이 키 포인트이다.