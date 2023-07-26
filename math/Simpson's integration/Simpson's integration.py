import math


def f(x):
    return math.sin(x)


lower_bound, upper_bound = 1, 7  # нижняя и верхняя границы интеграла
N = 2 * (10 ** 3)  # количество шагов (уже умноженное на 2)
h = (upper_bound - lower_bound) / N
integral = f(lower_bound)
for i in range(1, N):
    integral += f(lower_bound + h * i) * 2 * (2 if i & 1 else 1)
else:
    integral += f(lower_bound + h * N)
    integral *= h / 3
print(integral)
