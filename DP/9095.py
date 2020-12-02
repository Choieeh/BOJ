n = int(input())
num = [0 for i in range(n+1)]
arr = [0 for i in range(12)]

for i in range(n):
    num[i] = int(input())

arr[0] = 1
arr[1] = 2
arr[2] = 4

for i in range(n+1):
    for j in range(3, num[i]+1):
        if(arr[j] == 0):
            arr[j] = arr[j-3] + arr[j-2] + arr[j-1]

for i in range(n):
    print(arr[num[i]-1])