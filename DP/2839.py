N = input()
N = int(N)
count = 0
min = -1
f = 0;

#python에서 //은 몫을 나타냄~


if N % 5 == 0 :
    count = N / 5
    N = N % 5
    min = count

while N > 5*f :
    Num = N
    count = 0
    count += f
    Num = Num - 5*f
    if Num % 3 == 0 :
        count += Num // 3
        if min == -1 :
            min = count
        elif count < min :
            min = count

    f = f + 1
#5의 배수가 크면 무조건 이득
print(int(min))
    
'''
def func(num):
    if(num<3):
        return -1
    else:
        for i in range((num//3)+1):
            for j in range((num//5)+1):
                result= 3*i + 5*j
                if(result==num):
                    return i+j

        return -1

k=int(input())

print(func(k))
내가 원했던 DP solution
'''