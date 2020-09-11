from cs50 import get_string

# get the text from the user
text = get_string("Text: ")

# set the variables for counting
L, W, S = 0, 1, 0

# set the list of special characters pointer
points = [".", "!", "?", ":"]

# iterate the string counting letters, words and sentences
for i in range(0, len(text), 1):
    if str.isalpha(text[i]):
        L += 1

    if str.isspace(text[i]) and str.isalpha(text[i + 1]):
        W += 1

    if text[i] in points:
        S += 1

# calculate de Coleman-Liau index
index = 5.88 * L / W - 29.6 * S / W - 15.8

# label the text based on the index
if index <= 0:
    print("Before Grade 1")

elif index >= 16:
    print("Grade 16+")

else:
    print("Grade ", round(index))
