import sys
input = sys.stdin.readline

def bfs(start_node):
    visit = list()
    queue = list()
    queue.append(start_node)
    while queue:
        node = queue.pop(0)
        if node not in visit:
            print(node, end=' ')
            visit.append(node)
            queue.extend(graph[node])
            #extend는 list의 끝에 모든 항목을 덧붙여서 확장
    return visit

def dfs(start_node):
    visit = list()
    stack = list()
    stack.append(start_node)
    while stack:
        node = stack.pop()
        
        if node not in visit:
            print(node, end=' ')
            visit.append(node)
            stack.extend(graph[node])
    return visit

N, M, V = map(int, input().split())

graph={}
for i in range(M+1):
    graph[i] = []
    
for i in range(M):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

print(graph)

dfs(V)

bfs(V)