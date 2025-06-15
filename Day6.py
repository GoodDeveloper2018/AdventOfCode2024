def partOne():
    grid = []
    while True:
        try:
            line = input().strip()
            if line:
                grid.append(list(line))
        except EOFError:
            break

    R, C = len(grid), len(grid[0])
    dirs = ['^', '>', 'v', '<']
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]

    for r in range(R):
        for c in range(C):
            if grid[r][c] in dirs:
                x, y, d = r, c, dirs.index(grid[r][c])

    visited = set()
    while 0 <= x < R and 0 <= y < C:
        visited.add((x, y))
        nx, ny = x + dx[d], y + dy[d]
        if not (0 <= nx < R and 0 <= ny < C) or grid[nx][ny] == '#':
            d = (d + 1) % 4
        else:
            x, y = nx, ny
    return len(visited)

def partTwo():
    grid = []
    while True:
        try:
            line = input().strip()
            if line:
                grid.append(list(line))
        except EOFError:
            break

    R, C = len(grid), len(grid[0])
    dirs = ['^', '>', 'v', '<']
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]

    for r in range(R):
        for c in range(C):
            if grid[r][c] in dirs:
                sx, sy, sd = r, c, dirs.index(grid[r][c])

    def would_loop(block_r, block_c):
        g = [row[:] for row in grid]
        g[block_r][block_c] = '#'
        x, y, d = sx, sy, sd
        seen = set()
        for _ in range(R * C * 4):
            state = (x, y, d)
            if state in seen:
                return True
            seen.add(state)
            nx, ny = x + dx[d], y + dy[d]
            if not (0 <= nx < R and 0 <= ny < C) or g[nx][ny] == '#':
                d = (d + 1) % 4
            else:
                x, y = nx, ny
        return False

    count = 0
    for r in range(R):
        for c in range(C):
            if grid[r][c] == '.' and (r, c) != (sx, sy):
                if would_loop(r, c):
                    count += 1
    return count

if __name__ == "__main__":
    print(partOne())
    # print(partTwo())
