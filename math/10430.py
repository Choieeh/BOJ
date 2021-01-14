import sys
input = sys.stdin.readline

A, B, C = map(int, input().split())

print("{0}".format((A+B) % C))
print("{0}".format(((A % C) + (B % C)) % C))
print("{0}".format((A*B) % C))
print("{0}".format(((A%C)*(B%C)) % C))