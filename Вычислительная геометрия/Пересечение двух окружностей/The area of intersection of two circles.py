#Функция считает площадь пересечения двух окружностей
"""
Вход
Окружности задаются словарем со значениями: x - абсцисса центра окружности, y - ордината центра окружности, r - радиус окружности

Выход
На выходе функции два варианта значений:
Если окружности пересекаются, то площадь пересечения оружностей
Если окружности не пересекаются, то 0
"""
from math import pi, acos
def AreaCrossTwoCircles(Ccl1, Ccl2):
    distance = ((Ccl2['x'] - Ccl1['x']) ** 2 + (Ccl2['y'] - Ccl1['y']) ** 2) ** 0.5 #Расстояние между центрами окружностей
    if (distance > (Ccl1['r'] + Ccl2['r'])) or (distance == (Ccl1['r'] + Ccl2['r'])):    #Площадь пересечения = 0
        return 0
    elif distance < abs(Ccl2['r'] - Ccl1['r']):     #Одна окружность находится в другой
        return pi * min(Ccl1['r'], Ccl2['r']) ** 2  #Площадь пересечения равна окружности с меньшим радиусом
    else:
        a = (Ccl1['r'] ** 2 - Ccl2['r'] ** 2 + distance ** 2) / (2 * distance)
        b = distance - a
        h = (Ccl1['r'] ** 2 - a ** 2) ** 0.5
        S = (Ccl1['r'] ** 2 * acos(a/Ccl1['r']) - a * h) + (Ccl2['r'] ** 2 * acos(b/Ccl2['r']) - b * h)
        return S

""" Пример входных данных

Circle1 = {'x':6.1, 'y':4.9, 'r':2}
Circle2 = {'x':6.9, 'y':6.15, 'r':3}

print(AreaCrossTwoCircles(Circle1, Circle2))
"""
#Ответ: 11.28535060191815
