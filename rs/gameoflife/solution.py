from time import sleep


def check_neighbors(grid, r, c, max_r, max_c):
    count_alive = 0
    list_of1 = []

    if(r + 1 < max_r and c - 1 >= 0 and grid[r + 1][c - 1] == 1):
        count_alive += 1
    if(r + 1 < max_r and grid[r + 1][c] == 1):
        count_alive += 1
    if(r + 1 < max_r and c + 1 < max_c and grid[r + 1][c + 1] == 1):
        count_alive += 1

    if(r - 1 >= 0 and c - 1 >= 0 and grid[r - 1][c - 1] == 1):
        count_alive += 1
    if(grid[r - 1][c] == 1 and r - 1 >= 0):
        count_alive += 1
    if(c + 1 < max_c and r - 1 >= 0 and grid[r - 1][c + 1] == 1):
        count_alive += 1

    if(c - 1 >= 0 and grid[r][c - 1] == 1):
        count_alive += 1
    if(c + 1 < max_c and grid[r][c + 1] == 1):
        count_alive += 1

    if(count_alive == 3):
        list_of1.append([r, c])

    if(count_alive == 2 and grid[r][c] == 1):
        list_of1.append([r, c])

    return list_of1


def next_generation(grid):
    rows = 0
    cells = 0
    r_c = 0
    c_c = 0
    list_of1_big = []

    for row in grid:
        rows += 1

    for cell in grid[0]:
        cells += 1

    for row in grid:
        for cell in row:
            # print(r_c, c_c)
            list_of1_big.append(check_neighbors(grid, r_c, c_c, rows, cells))
            c_c += 1
        r_c += 1
        c_c = 0

    grid = [[0 for i in range(rows)] for k in range(cells)]

    for i in list_of1_big:
        for el in i:
            grid[el[0]][el[1]] = 1
    return grid


def print_grid(grid):
    for row in grid:
        for cell in row:
            print('■' if cell else '□', end=' ')
        print('')


def animate(grid):
    generation = grid
    while True:
        print('')
        print('')
        print_grid(generation)
        sleep(1)
        generation = next_generation(generation)


g = [[0 for i in range(5)] for k in range(5)]
g[2][1] = 1
g[2][2] = 1
g[2][3] = 1
g[1][3] = 1
g[0][2] = 1

animate(g)
