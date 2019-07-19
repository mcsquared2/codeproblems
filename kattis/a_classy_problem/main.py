import sys

cases = int(sys.stdin.readline().strip())

def classToNumber(c):
    converter = {
        'upper': 3,
        'middle': 2,
        'lower': 1
    }
    return converter[c]

for _ in range(cases):
    num_peeps = int(sys.stdin.readline().strip())
    peeps = []
    max_length = 0
    for i in range(num_peeps):
        name, peep_class, _ = sys.stdin.readline().split()
        name = name[:-1]
        peep_class = peep_class.split('-')
        peep_class.reverse()
        peeps.append({'name': name, 'class': peep_class})
        if len(peep_class) > max_length:
            max_length = len(peep_class)

    for peep in peeps:
        value = 0
        for i in range(max_length):
            if i < len(peep['class']):
                value += classToNumber(peep['class'][i])
            else:
                value +=2
            value *= 10
        peep['value'] = value
    peeps = sorted(peeps, key=lambda elem:elem['name'])
    sorted_peeps = sorted(peeps, key=lambda elem:elem['value'], reverse=True)

    # sorted_peeps = sorted_peeps.reverse()
    for peep in sorted_peeps:
        print(peep['name'])
    print('='*30)


     
    