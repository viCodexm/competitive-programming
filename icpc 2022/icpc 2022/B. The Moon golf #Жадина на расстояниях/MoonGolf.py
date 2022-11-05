craters = [] #Список кратеров
meteors = [] #Список метеоритов
max_dist = lambda x: (10 ** 6 / x) ** 0.5 #Макс. дист., на которую можно забросить метеорит
to_crat = lambda x, y: (x ** 2 + y ** 2) ** 0.5 #Расст. от игрока до центра кратера

exite = [] #Номера метеоритов и кратеров, куда их можно наивыгоднее забросить

input()
for i, m in enumerate(list(map(int, input().split(' '))), start=1): #Вводим номер и массу метеоритов и сразу считаем макс. дист.
    meteors.append({'N':i,'d':max_dist(m)})

meteors.sort(key=lambda x: x['d']) #Сортируем метеориты от самого тяжелого до самого легкого

for i in range(1, int(input())+1): #Вводим параметры кратеров и сразу считаем расст. до их ближайщей точки на границе
    vvod = list(map(int, input().split(' ')))
    craters.append({'N':i ,'d':to_crat(vvod[0], vvod[1])-vvod[2]})

craters.sort(key=lambda x: x['d']) #Сортируем кратеры от самого ближнего до самого дальнего

while meteors and craters: #Пока остались кратеры или метеориты делаем
        if meteors[0]['d'] >= craters[0]['d']: #Можно ли забросить метеорит в кратер
            exite.append([meteors[0]['N'], craters[0]['N']])
            meteors.pop(0) #Удаляем из списка метеорит
            craters.pop(0) #Удаляем из списка кратер
        else: #Не можем забросить метеорит
            meteors.pop(0) #Удаляем из списка метеорит


exite.sort(key=lambda x: x[0]) #Сортируем по номерам появления метеоритов

if not exite: #Вывод
    print(0)
else:
    print(len(exite))
    for i in exite:
        print(i[0], ' ', i[1])