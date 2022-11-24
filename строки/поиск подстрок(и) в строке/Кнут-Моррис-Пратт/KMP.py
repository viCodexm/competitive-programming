def Z_func(sample): #Зет-функция
    Z = [0] * len(substr) #Кол-во элементов Z-функции = кол-ву символов подстроки
    j, i = 0, 1
    while i < len(substr): #Пока не перебрали все символы
        if substr[j] == substr[i]:  #Если префикс равен суффиксу
            Z[i] = j + 1 #Записываем в массив длину совпавшего префикса с суфиксом
            i += 1; j += 1 #Переходим на следущий символ, расширяя префикс
        elif j == 0: #Минимальный префикс не равен минимальному суфиксу
            Z[i] = 0 
            i += 1
        else:   #Если символы не совпали, то
            j = Z[j - 1]   #Переходим на индекс предыдущего совпашего префикса
    return Z

def KMP(str, substr, zeta): #Поиск подстроки по Z-функции
    i, j = 0, 0
    poz = []
    while i < len(str):
        if str[i] == substr[j]:
            i += 1; j += 1
            if j == len(substr):
                poz.append(i - j)
                j = zeta[j-1]
        elif j == 0:
            i += 1
        else:
            j = zeta[j - 1]
    if not poz: #Не нашли подстроки
        poz = [-1]
    return poz

str1 = 'hahaohalhahaloha' #Строка, где выполняем поиск
substr = 'haloha' #Подстрока, которую ищем

zeta = Z_func(substr)
num = KMP(str1, substr, zeta) #Все позиции вхождения подстроки в строку

print(num)
