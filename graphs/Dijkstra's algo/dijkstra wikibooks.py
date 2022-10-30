#N — количество вершин
#S — номер стартовой вершины (отсчитывая от нуля)
#matrix — матрица смежности исходного графа, где несуществующие рёбра имеют бесконечный вес - float('inf')
def Dijkstra(N, S, matrix):
	valid = [True]*N        
	weight = [float('inf')]*N
	weight[S] = 0
	for i in range(N):
		min_weight = float('inf')
		ID_min_weight = -1
		for j in range(N):
			if valid[j] and weight[j] < min_weight:
				min_weight = weight[j]
				ID_min_weight = j
		for z in range(N):
			if weight[ID_min_weight] + matrix[ID_min_weight][z] < weight[z]:
				weight[z] = weight[ID_min_weight] + matrix[ID_min_weight][z]
		valid[ID_min_weight] = False
	return weight


#Пример вызова функции с 4-мя вершинами
"""
inf = float('inf') #Определяем имя для бесконечности
mat = [[0,2,4,inf], #Матрица смежности графа
      [inf,0,4,8],
      [inf,8,0,1],
      [8,6,inf,0]]

print(Dijkstra(4,3,mat)) #Вызов функции с аргументами - кол-во вершин 4, поиск маршрута для четвертой вершины, сама матрица
"""
#Вывод [8, 6, 10, 0]
