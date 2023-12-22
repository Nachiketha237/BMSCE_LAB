import sys

# Function to print the Tic Tac Toe board
def print_board(board):
    for row in board:
        print(" ".join(row))
    print()

# Function to check if a player has won
def check_winner(board, player):
    # Check rows, columns, and diagonals for a win
    for i in range(3):
        if all(board[i][j] == player for j in range(3)):
            return True
        if all(board[j][i] == player for j in range(3)):
            return True
    if all(board[i][i] == player for i in range(3)) or all(board[i][2 - i] == player for i in range(3)):
        return True
    return False

# Function to check if the board is full
def is_board_full(board):
    return all(board[i][j] != ' ' for i in range(3) for j in range(3))

# Function for the Minimax algorithm
def minimax(board, depth, is_maximizer):
    scores = {
        'X': 10 - depth,
        'O': depth - 10,
        'Tie': 0
    }

    if check_winner(board, 'X'):
        return scores['X']
    elif check_winner(board, 'O'):
        return scores['O']
    elif is_board_full(board):
        return scores['Tie']

    if is_maximizer:
        best_score = -sys.maxsize
        for i in range(3):
            for j in range(3):
                if board[i][j] == ' ':
                    board[i][j] = 'X'
                    score = minimax(board, depth + 1, False)
                    board[i][j] = ' '
                    best_score = max(best_score, score)
        return best_score
    else:
        best_score = sys.maxsize
        for i in range(3):
            for j in range(3):
                if board[i][j] == ' ':
                    board[i][j] = 'O'
                    score = minimax(board, depth + 1, True)
                    board[i][j] = ' '
                    best_score = min(best_score, score)
        return best_score

# Function to find the best move for AI using Minimax
def find_best_move(board):
    best_score = -sys.maxsize
    best_move = (-1, -1)

    for i in range(3):
        for j in range(3):
            if board[i][j] == ' ':
                board[i][j] = 'X'
                score = minimax(board, 0, False)
                board[i][j] = ' '

                if score > best_score:
                    best_score = score
                    best_move = (i, j)

    return best_move

# Function to play the Tic Tac Toe game
def play_game():
    board = [[' ' for _ in range(3)] for _ in range(3)]
    print("Welcome to Tic Tac Toe!")
    print_board(board)

    while not check_winner(board, 'X') and not check_winner(board, 'O') and not is_board_full(board):
        # Player's move
        player_row, player_col = map(int, input("Enter your move (row and column): ").split())
        if board[player_row][player_col] != ' ':
            print("Invalid move. Try again.")
            continue
        board[player_row][player_col] = 'O'
        print_board(board)

        if check_winner(board, 'O'):
            print("Congratulations! You win!")
            break

        if is_board_full(board):
            print("It's a tie!")
            break

        # AI's move
        print("AI's move:")
        ai_row, ai_col = find_best_move(board)
        board[ai_row][ai_col] = 'X'
        print_board(board)

        if check_winner(board, 'X'):
            print("AI wins!")
            break

        if is_board_full(board):
            print("It's a tie!")
            break

# Start the game
play_game()
