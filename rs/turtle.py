# 0 = ->
# 1 = | надолу
# 2 = <-
# 3 = ^|
from math import floor

class Turtle:
    def __init__(self, rows, columns):
        self.rows = rows
        self.columns = columns
        self.canvas = [[0 for i in range(columns)] for j in range(rows)]
        self.curr_r = None
        self.curr_c = None
        self.orientation = 0

    def spawn_at(self, r, c):
        self.curr_r = r
        self.curr_c = c
        self.canvas[self.curr_r][self.curr_c] += 1

    def _validate(self):
        if(self.curr_c is None):
            raise RuntimeError

    def move(self):
        self._validate()

        if self.orientation == 0:
            self.curr_c += 1
        if self.orientation == 1:
            self.curr_r += 1
        if self.orientation == 2:
            self.curr_c -= 1
        if self.orientation == 3:
            self.curr_r -= 1

        self.curr_c %= self.columns
        self.curr_r %= self.rows

        self.canvas[self.curr_r][self.curr_c] += 1

    def turn_right(self):
        self._validate()

        self.orientation = (self.orientation + 1) % 4

    def turn_left(self):
        self._validate()

        self.orientation = (self.orientation - 1) % 4


class SimpleCanvas:
    def __init__(self, canvas, list_symbols):
        self.canvas = canvas
        self.list_symbols = list_symbols
        self.max = max(map(max, canvas))
        self.canvas2 = []

    def draw(self):
        lenn = len(self.list_symbols)
        a = self.max/(lenn - 1)

        self.canvas2 = [[self.list_symbols[floor(e/a)] for e in row] for row in self.canvas]

for i in range(len(self.canvas)):
                for j in range(len(self.canvas[0])):
                    if self.canvas[i][j] == 0.0:
                        self.canvas2[i][j] = self.list_symbols[0]
                    if self.canvas[i][j] > list_of_nums[k] and self.canvas[i][j] <= list_of_nums[k + 1]:
                        self.canvas2[i][j] = self.list_symbols[k + 1]
            

        for i in range(len(self.canvas2)):
            self.canvas2[i] = "".join(self.canvas2[i])
        res = "\n".join(self.canvas2)
            
        print(self.canvas)

        return res


turtle = Turtle(3, 3)
turtle.spawn_at(0, 0)

for i in range(9):
    turtle.move()
turtle.turn_right()
for i in range(4):
    turtle.move()
turtle.turn_left()
turtle.move()
turtle.move()
turtle.turn_right()
turtle.move()
canvas = SimpleCanvas(turtle.canvas, [' ', '*', '@', '#', 'd', '/'])

print(canvas.draw())
print(canvas.draw())
print(canvas.draw())

if(canvas.draw() == "#@@\n@**\n* *"):
    print ("TRUE")
else:
    print("FALSE")
