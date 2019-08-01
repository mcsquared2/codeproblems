import sys

cases = int(sys.stdin.readline())
results = {}
pages = {}

def traverse(page):
    if page not in results:
        results[page] = traverse(pages[page][0]) + traverse(pages[page][1]) + traverse(pages[page][2])
    return results[page]  

for _ in range(cases):
    results = {}
    pages = {}
    num_pages = int(sys.stdin.readline().strip())
    for _ in range(num_pages):
        line = sys.stdin.readline().split()
        if line[1][0] == 'f':
            results[line[0]] = 1
        elif line[1][0] == 'c':
            results[line[0]] = 0
        else:
            pages[line[0]] = line[1:]

    print(traverse('1'))