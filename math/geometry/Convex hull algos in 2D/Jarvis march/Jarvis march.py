# Класс для векторов и точек
class Vector:
    # Создаем и инициализируем вектор
    def __init__(self, x, y):
        self.x = x
        self.y = y

    # Перегружаем операцию "*", чтобы она считала косое произведение
    def __mul__(self, other):
        return self.x * other.y - self.y * other.x

    # Перегружаем операцию "-", чтобы она считала по двум точкам координаты вектора
    def __sub__(self, other):
        return Vector(self.x - other.x, self.y - other.y)

    # Длина вектора
    def __abs__(self):
        return (self.x ** 2 + self.y ** 2) ** 0.5

    # Для преобразования из типа Vector в тип str
    def __repr__(self):
        return f"{self.x, self.y}"


# Сам алгоритм
def jarvis_march(points):

    # Сначала находим самую нижнюю левую точку (храним ее индекс)
    start_point = 0
    for i in range(1, len(points)):
        if points[i].y < points[start_point].y:
            start_point = i
        elif points[i].y == points[start_point].y:
            if points[i].x < points[start_point].x:
                start_point = i

    # Ставим эту точку первой в исходном списке
    points[0], points[start_point] = points[start_point], points[0]
    start_point, next_point = 0, 1

    # Добавляем индекс первой точки в ответ
    convex_hull = [start_point]

    # Строим выпуклую оболочку
    while True:
        # Теперь проверяем косые произведения
        for i in range(len(points)):

            # Сравниваемые векторы
            start_vector, next_vector = points[next_point] - points[start_point], points[i] - points[start_point]

            # Косое произведение
            skew_prod = start_vector * next_vector

            # Если точка лежит "правее" от предыдущей или обе точки лежат на одной линии (выбираем самую удаленную)
            if (skew_prod < 0) or (skew_prod == 0 and abs(next_vector) > abs(start_vector)):
                next_point = i

        # Если новая точка оказалась самой первой, заканчиваем алгоритм
        if next_point == 0:
            break

        # Добавляем индекс точки в ответ
        convex_hull.append(next_point)

        # следующая точка становится начальной
        start_point = next_point

    return convex_hull


input()
inp = [int(x) for x in input().split()]
points = []

for i in range(0, len(inp), 2):
    points.append(Vector(inp[i], inp[i + 1]))

print(points)
ans = jarvis_march(points)

# Вывести на экран точки, вошедшие в выпуклую оболочку
print(*(points[i] for i in ans))

"""
Input:
9
1 1 4 3 2 0 2 2 4 1 3 2 3 4 1 3 2 3

Output:
(2, 0) (4, 1) (4, 3) (3, 4) (1, 3) (1, 1)
"""