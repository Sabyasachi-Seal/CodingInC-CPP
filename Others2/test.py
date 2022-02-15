# S5.1: Follow the instructions mentioned in the comments below. Accordingly, write the code.
# Import the random module below.

import random
# Initialise the 'player_score' and 'computer_score' variables below.
player_score = 0
computer_score = 0
while player_score<5 and computer_score<5:
    # Predict 0 or 1 randomly below.
    computer_predicted = random.randint(0, 1)
    # Take input from the player below.
    player_input = int(input("Enter either 0 or 1: "))
    while player_input>1:
        print("Invalid Input")
        player_input = int(input("Enter either 0 or 1: "))
    # Convert the value stored in the 'player_input' variable into an integer value below.
    # Compare the 'predict' and the 'player_input' values below.
    if player_input==computer_predicted:
        computer_score += 1
    else:
        player_score += 1
    print(f"Player Score = {player_score}\nComputer Score = {computer_score}")
    # Compare the 'computer_score' and 'player_score' values with 10.
print("Computer Won" if computer_score>player_score else "Player Won")