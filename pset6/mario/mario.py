import cs50

# asks for the input until a valid one:
while True:
    n = cs50.get_int("Height: ")
    # condition to exit the while loop
    if not (n < 1 or n > 8):
        break
# print the hashes
for i in range(0, n, 1):
    print(" " * (n - 1 - i) + "#" * (i + 1))
