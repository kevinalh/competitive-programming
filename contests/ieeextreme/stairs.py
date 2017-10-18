import sys, io

N = 22005
l = []

l.append(1)
l.append(1)

for i in range(2, N):
    l.append(l[i-1] + l[i-2])

t = int(input())

for i in range(t):
    n = int(input())
    print(l[n+1])
