# Расширенный алгоритм Евклида
Данный алгоритм вычисляет, кроме НОД целых чисел a и b, ещё и коэффициенты соотношения Безу, то есть целые x и y, такие что **ax + by = НОД(a, b)**.

По сути он ищет вектор **(x, y)**, скалярное произведение с которым для вектора **(a, b)** дало бы **НОД(a, b)**. 

## Доказательство рекурсивной реализации
[Статья](https://ru.algorithmica.org/cs/modular/extended-euclid/)

[Видео](https://www.youtube.com/watch?v=4lGmcnWIi0Q)

## Применение
Используется для:
* поиска обратного элемента по модулю. [Как искать обратный элемент (видео)](https://www.youtube.com/watch?v=jwWeITPGJTI)
* решения диофантовых уравнений вида **ax + by = c**. [Принцип работы самого алгоритма + как решать диоф. ур. (видео)](https://www.youtube.com/watch?v=Ta5Tw1wSars#t=42m10s)
    
## Рекурсивная реализация на Python
```python
def recGCD_EXT(a, b):
    if b == 0:
        return a, 1, 0
    x, y, d = gcd_ext(b, a % b)
    return y, x - y * (a // b), d
```
## Итерационная реализация на Python
```python
def GCD_EXT(a, b):
    x, xx, y, yy = 1, 0, 0, 1
    while b:
        q = a // b
        a, b = b, a % b
        x, xx = xx, x - xx * q
        y, yy = yy, y - yy * q
    return x, y, a
```

Возвращают кортеж **(x, y, НОД(a, b))**
<br></br>
<h1>:warning:Нужна доработка статьи</h1>

:question: Доказательство итерационной реализации

:question: мб что-то еще
