
a = 3.5
b = int(3.5)
print(a**((a // b) * 2))
print(((a - b) * a) // b)
b = (((a - b) * a) % b)
print(b)
print((a * 4) % (b * 4))