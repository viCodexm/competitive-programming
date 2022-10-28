
import math

def f(x):
    return math.sin(x)


lower_bound, upper_bound = 1, 7 #нижняя и верхняя границы интеграла
N = 1000*1000; #количество шагов (уже умноженное на 2)
integral = 0
h = (upper_bound - lower_bound) / N
for i in range(N + 1):
    x = lower_bound + h * i
    if (i == 0 or i == N):
        integral += f(x)
    else:
        if (i&1 == 0):
            integral += f(x) * 2
        else: integral += f(x) * 4

integral *= h / 3
print(integral)