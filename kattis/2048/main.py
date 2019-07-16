import sys

LEFT = 0
UP = 1
RIGHT = 2
DOWN = 3

# read data into 2d array
data = []
for i in range(4):
    data.append(sys.stdin.readline().split())
    data[i] = [ int(val) for val in data[i] ]
# print("data:")
# for line in data:
#     print(" ".join([ str(val) for val in line]))

data_condensed = []
for i in range(len(data)):
    data_condensed.append([False] * 4)


# read the direction
direction = int(sys.stdin.readline().strip())

def opposite(n):
    return len(data) - 1 - n

def move(direction, x, y):
    if ( direction == LEFT and x == 0 or 
        direction == RIGHT and x == len(data)-1 or
        direction == UP and y == 0 or
        direction == DOWN and y == len(data)-1 
    ):
        return
        
    if direction == LEFT:
        if data[y][x-1] == 0:
            data[y][x-1], data[y][x] = data[y][x], data[y][x-1]
            move(direction, x-1, y)
        elif data[y][x-1] == data[y][x] and not data_condensed[y][x-1]:
            data[y][x-1] *= 2
            data[y][x] = 0
            data_condensed[y][x-1] =True
    if direction == RIGHT:
        if data[y][x+1] == 0:
            data[y][x+1], data[y][x] = data[y][x], data[y][x+1]
            move(direction, x+1, y)
            return
        if data[y][x+1] == data[y][x] and not data_condensed[y][x+1]:
            data[y][x+1] *= 2
            data[y][x] = 0
            data_condensed[y][x+1] =True
            
    if direction == UP:
        if data[y-1][x] == 0:
            data[y-1][x], data[y][x] = data[y][x], data[y-1][x]
            move(direction, x, y-1)
            return
        if data[y-1][x] == data[y][x] and not data_condensed[y-1][x]:
            data[y-1][x] *= 2
            data[y][x] = 0
            data_condensed[y-1][x] =True

    if direction == DOWN:
        if data[y+1][x] == 0:
            data[y+1][x], data[y][x] = data[y][x], data[y+1][x]
            move(direction, x, y+1)
            return
        if data[y+1][x] == data[y][x] and not data_condensed[y+1][x]:
            data[y+1][x] *= 2
            data[y][x] = 0
            data_condensed[y+1][x] =True    


for x in range(len(data)):
    for y in range(len(data)):

        if direction == LEFT:
            move(LEFT, x, y)
        if direction == RIGHT:
            move(RIGHT, opposite(x), y)
        if direction == UP:
            move(UP, x, y)
        if direction == DOWN:
            move(DOWN, x, opposite(y))
for line in data:
    print(" ".join([str(val) for val in line]))