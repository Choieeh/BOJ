import sys
import heapq
input = sys.stdin.readline

T = int(input())

for t in range(T):
    count = 0
    N = sys.stdin.readline()
    size = list(map(int, input().split()))
    q = []
    for i in size:
        heapq.heappush(q, i)
    while len(q) > 1:
        a = heapq.heappop(q)
        b = heapq.heappop(q)
        count = count + a + b
        heapq.heappush(q, a+b)
    print(count)
    
    
'''
heapq 라는 module을 사용해야 함.

힙은 모든 부모 노드가 자식보다 작거나 같은 값을 갖는 이진 트리
구글 문서 참조
'''