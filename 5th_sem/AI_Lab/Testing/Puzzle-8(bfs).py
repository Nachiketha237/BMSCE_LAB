from collections import deque

# Function to find the index of '0' in the puzzle
def find_zero(puzzle):
    for i in range(3):
        for j in range(3):
            if puzzle[i][j] == 0:
                return i, j

# Function to generate next possible states
def generate_next_states(state):
    next_states = [] 
    zero_i, zero_j = find_zero(state)
    
    # Possible movements
    movements = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    
    for move in movements:
        new_i, new_j = zero_i + move[0], zero_j + move[1]
        if 0 <= new_i < 3 and 0 <= new_j < 3:
            new_state = [row[:] for row in state]
            new_state[zero_i][zero_j], new_state[new_i][new_j] = new_state[new_i][new_j], new_state[zero_i][zero_j]
            next_states.append(new_state)
    
    return next_states

# Function to check if the puzzle is solved
def is_goal(state):
    return state == [[0, 1, 2], [3, 4, 5], [6, 7, 8]]

# Breadth-First Search Algorithm
def bfs(start):
    queue = deque([(start, [])])
    visited = set()
    
    while queue:
        current_state, path = queue.popleft()
        visited.add(str(current_state))
        
        if is_goal(current_state):
            return path
        
        for next_state in generate_next_states(current_state):
            if str(next_state) not in visited:
                queue.append((next_state, path + [next_state]))
                visited.add(str(next_state))
    
    return None

# Example puzzle
initial_state = [
    [1, 2, 3],
    [0, 4, 5],
    [6, 7, 8]
]

# Solve the puzzle
solution = bfs(initial_state)

if solution:
    print("Solution found!")
    print("Steps to reach the goal:")
    for step in solution:
        print(step)
else:
    print("No solution exists for this puzzle.")
