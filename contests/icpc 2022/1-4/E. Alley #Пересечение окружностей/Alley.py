from math import pi, acos


def AreaCrossTwoCircles(Ccl1, Ccl2):
    distance = ((Ccl2['x'] - Ccl1['x']) ** 2 + (Ccl2['y'] - Ccl1['y']) ** 2) ** 0.5 #Расстояние между центрами окр.
    if (distance > Ccl1['r'] + Ccl2['r']) or distance == (Ccl1['r'] + Ccl2['r']):    #Площадь пересечения = 0
        return 0
    else:
        a = (Ccl1['r'] ** 2 - Ccl2['r'] ** 2 + distance ** 2) / (2 * distance)
        b = distance - a
        h = (Ccl1['r'] ** 2 - a ** 2) ** 0.5
        S = (Ccl1['r'] ** 2 * acos(a/Ccl1['r']) - a * h) + (Ccl2['r'] ** 2 * acos(b/Ccl2['r']) - b * h)
        return S


SquareCircle = lambda x : pi * x**2 #Формула площади окружности

Square = 0 #Площадь пересечения окружностей
massCircles = [] #Список окружностей
countCircles = int(input()) #Количество окружностей

for i in range(countCircles): #Вводим параметры окружностей
    vvod = list(map(int, input().split(' ')))
    circle = {'x':vvod[0], 'y':0, 'r':vvod[1]}
    massCircles.append(circle)

massCircles.sort(key=lambda x: x['x']) #Сортируем список по координате X

for i in range(countCircles-1): #Обрабатываем окружности слева направо
    Square += SquareCircle(massCircles[i]['r']) #Прибавляем площадь окр.
    Square -= AreaCrossTwoCircles(massCircles[i], massCircles[i+1]) #Вычитаем площадь пересечения двух соседних окр.

Square += SquareCircle(massCircles[countCircles-1]['r']) #Не забываем про последнюю окр.
print(Square)
