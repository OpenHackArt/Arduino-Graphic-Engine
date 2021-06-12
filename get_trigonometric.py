import math

for deg in range(0, 360):
    tan_val = math.tan(deg * math.pi / 180)
    cot_val = None
    if tan_val == 0:
        cot_val = -99999999
    else:
        cot_val = 1 / tan_val
    print(cot_val, end=", ")
