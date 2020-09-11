from cs50 import get_float

# repeat until user input a valid number
while True:
    change = get_float("Change owed: ")
    # condition to exit the while loop
    if not change < 0:
        break

# round your cents to the nearest penny
cents = round(change * 100)
coins = 0
coins_faces = [25, 10, 5, 1]

for i in range(len(coins_faces)):
    while cents >= coins_faces[i]:
        cents -= coins_faces[i]
        coins += 1

print(coins)