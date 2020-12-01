N = int(input())

arr = [0 for i in range(N+1)]

arr[1] = 0

for i in range(2, N+1):
    arr[i] = arr[i-1] + 1
    if(i % 2 == 0):
        arr[i] = min(arr[i], arr[i//2]+1)
    if(i % 3 == 0):
        arr[i] = min(arr[i], arr[i//3]+1)
        
print(arr[N])

#DP 할때는 이전식을 구할수 있는지 부터 확인!
#여기서는 arr를 통해 1번부터 N까지 차례로 구해나감


#https://stonejjun.tistory.com/24