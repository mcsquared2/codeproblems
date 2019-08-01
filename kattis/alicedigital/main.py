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
        s = a[i] + m + a[i+1]
        # print(mx, s)
        if mx < s:
            # print('Changing mx to {}'.format(s))
            mx = s

    print(mx)