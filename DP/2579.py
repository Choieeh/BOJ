n = int(input())

score = [0 for i in range(n+1)]
stair = [0 for i in range(n+1)]
for i in range(1, n+1):
    stair[i] = int(input())

count = 0

score[0] = 0
score[1] = stair[1]
if n>=2 :
    score[2] = stair[1]+stair[2]

if n > 2:
    for i in range(3, n+1):
        score[i] = max(score[i-3]+stair[i-1]+stair[i], score[i-2]+stair[i])

print(score[n])


'''
n번째면 n-1 && count = 1
count = 0
count = 1
   or  n-2 count++
   ooooo
       
'''