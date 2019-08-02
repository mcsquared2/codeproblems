import sys


cases = int(sys.stdin.readline().strip())

for _ in range(cases):
    n, m = sys.stdin.readline().split()
    n = int(n)
    m = int(m)
    a= []
    s = 0
    for i in sys.stdin.readline().split():
        i = int(i)
        if i == m:
            a.append(s)
            s = 0
        else:
            s += i
    a.append(s)
    mx = 0
    # print(a)
    for i in range(len(a)-1):
        mx = max(mx, a[i]+a[i+1])

    print(mx + m) 