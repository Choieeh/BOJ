import sys
input = sys.stdin.readline
num = 9


key = [0 for i in range(9)]
Allsum = 0
deli = 0
delj = 0
end_flag = 0

for i in range(num):
    key[i] = int(input())
    Allsum += key[i]

for i in range(num):
    for j in range(i+1, num):
        if(Allsum - (key[i] + key[j]) == 100):
            deli = i
            delj = j
            end_flag = 1
            break
    if end_flag == 1:
        break


del key[delj]
del key[deli]

key.sort()

for i in range(num-2):
    print(key[i])
    
#del 함수가 아닌 key.remove(key[i]) 이런식으로해도 된다.