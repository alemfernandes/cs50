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

while cents >= 25:
    cents -= 25
    coins += 1

while cents >= 10:
    cents -= 10
    coins += 1

while cents >= 5:
    cents -= 5
    coins += 1

while cents >= 1:
    cents -= 1
    coins += 1

print(coins)
