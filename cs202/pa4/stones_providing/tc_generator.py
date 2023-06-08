import random

with open("tc.txt", "w") as f:
    for i in range(1, 600):
        target = random.randint(1, 100)
        f.write(str(target) + " ")

    