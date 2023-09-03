import pygame as pg
from random import randint, uniform

# Размер окна в пикселях (ширина, высота)
display_size = (1400, 800)

# Инициализируем объекты графической библиотеки
pg.init()

# Создаем графическое окно
sc = pg.display.set_mode(display_size)

# Константа - белый цвет
WHITE = pg.Color(255, 255, 255)


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

    # Перемещаем центр координат в центр окна
    # и чтобы ось X была направлена ВПРАВО относительно плоскости экрана компьютера, а ось Y - ВВЕРХ
    def to_pygame(self):
        return display_size[0] // 2 + self.x, display_size[1] // 2 - self.y


# Границы координат точек для автоматического создания (допустимые диапазоны по x и по y)
borders_points_X = -display_size[0] // 2 + 50, display_size[0] // 2 - 50
borders_points_Y = -display_size[1] // 2 + 50, display_size[1] // 2 - 50


def generateNewpoints(count_points):
    # Список точек
    points = [Vector(uniform(*borders_points_X), uniform(*borders_points_Y)) for _ in range(count_points)]

    # Если добавить вершины ниже, то сложность алгоритма O(4n) = O(n)
    """
    points.extend([Vector(borders_points_X[0] - 25, borders_points_Y[0] - 25), Vector(borders_points_X[1] + 25, borders_points_Y[0] - 25),
                 Vector(borders_points_X[1] + 25, borders_points_Y[1] + 25), Vector(borders_points_X[0] - 25, borders_points_Y[1] + 25)])
    """
    return points


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

        # Рисуем линию между старой и новой граничными точками
        pg.draw.line(sc, WHITE, points[start_point].to_pygame(), points[next_point].to_pygame())

        # Если новая точка оказалась самой первой, заканчиваем алгоритм
        if next_point == 0:
            break

        # Добавляем индекс точки в ответ
        convex_hull.append(next_point)

        # следующая точка становится начальной
        start_point = next_point

    # Рисуем созданные точки
    for v in points:
        pg.draw.circle(sc, WHITE, v.to_pygame(), 2)
    pg.display.update()

    return convex_hull


# Количество точек для создания (должно быть больше 1)
count_points = 100

# Создаем множество точек
points = generateNewpoints(count_points)
ans = jarvis_march(points)

# Вывести на экран точки, вошедшие в выпуклую оболочку
# print(*(points[i] for i in ans))

# Чтобы лишний раз не нагружать процессор
FPS = 30
clock = pg.time.Clock()

while True:
    # Цикл событий
    for event in pg.event.get():
        # Выход из программы (нажали на крестик)
        if event.type == pg.QUIT:
            exit()
        # При нажатии на клавишу "Стрелка вверх", создаются новые точки и ВО для них
        if event.type == pg.KEYDOWN and event.key == pg.K_UP:
            sc.fill((0, 0, 0))
            jarvis_march(generateNewpoints(count_points))
    clock.tick(FPS)
