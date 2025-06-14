import sys

# EXERCISE 13
wlength = 0
anotherlength = 0
lengtharr = [0 for i in range(9)]

# Read input as a string
data = sys.stdin.read()

# Use ctrl + D (linux) / ctrl + Z (windows) to end the execution of the program (EOF)
for c in data:
    if c == ' ' or c == '\n' or c == '\t':
        if wlength > 0:
            if wlength < len(lengtharr):
                lengtharr[wlength] += 1
            else:
                anotherlength += 1
            wlength = 0
    else:
        wlength += 1

# Count the last word even if it doesnt end with a separator
if wlength > 0:
    if wlength < len(lengtharr):
        lengtharr[wlength] += 1
    else:
        anotherlength += 1

for i, val in enumerate(lengtharr):
    print(f"{i}: {'#' * val}")
if anotherlength > 0:
    print(f"Words with length >= {len(lengtharr)}: {anotherlength}")