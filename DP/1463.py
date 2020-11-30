N = int(input())

answer = 0
count = 0
if N == 1:
    answer = 0
else:
    while(N != 1):
        if N % 3 == 0:
            N = N // 3
            count=count+1
        elif N % 2 == 0:
            N = N // 2
            count=count+1
        else:
            N = N - 1
            count=count+1

answer = count
print(answer)

