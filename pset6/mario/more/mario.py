from cs50 import get_int

height = 0

while(True):
    height = get_int("Height? ")
    if (height < 9 and height > 0):
        break

for i in range(1, height + 1, 1):
    # print("Hello")
    print(" " * (height - i) + "#" * i + "  " + "#" * i)
