global placements, count
placements, count = None, None


def main():
    global placements, count
    board = [input() for _ in range(8)]
    placements = [[False for _ in range(8)] for _ in range(8)]
    column = [0 for _ in range(8)]
    count = 0

    def is_legal(x, y):
        if board[x][y] == '.' and column[y] == 0:
            for i in range(x):
                for j in range(8):
                    if placements[i][j] and abs(x-i) == abs(y-j):
                        return False
            return True
        return False

    def backtrack(x):
        global placements, count
        if x == 8:
            count += 1
            return
        for y in range(8):
            if is_legal(x, y):
                column[y] = 1
                placements[x][y] = True
                backtrack(x+1)
                column[y] = 0
                placements[x][y] = False

    backtrack(0)
    print(count)


main()
