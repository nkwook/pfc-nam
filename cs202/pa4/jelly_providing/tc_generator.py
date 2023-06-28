import random

# Generate the shuffled integer range
numbers = list(range(1, 1001))
random.shuffle(numbers)

# Create a new text file and write the shuffled numbers to it
with open('shuffled_numbers.txt', 'w') as file:
    for number in numbers:
        file.write(str(number) + ' ')
