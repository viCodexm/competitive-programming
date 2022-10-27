//visited - массив посещенных вершин( индекс равен номеру вершины);
//w - матрица путей(хранит вес ребер), где несуществующие ребра имеют бесконечный вес;
//D - массив минимальных путей;
//INT_MAX - Максимальный размер типа int, принимаемый за бесконечность;
//start - номер источника
void Dijkstra(int n, int start)
{
    vector<vector<int>> w(n, vector<int>(n));
    vector<bool> visited(n, false);
    vector<int> D(n);
    
    for (int i = 0; i < n; ++i)
        D[i] = w[start][i];
    
    D[start] = 0;
    int index = 0, u = 0;
    for (int i = 0; i < n; ++i) {
        int min = INT_MAX;
        for (int j = 0; j < n; ++j)
            if (!visited[j] && D[j] < min) {
                min = D[j];
                index = j;
            }

        u = index;
        visited[u] = true;
        for (int j = 0; j < n; j++)
            if (!visited[j] && w[u][j] != INT_MAX && D[u] != INT_MAX && (D[u] + w[u][j] < D[j]))
                D[j] = D[u] + w[u][j];
    }

    cout << "Стоимость пути из начальной вершины до остальных:\t\n";
    for (int i = 0; i < n; i++)
        if (D[i] != INT_MAX)
            cout << start << " -> " << i << " = " << D[i] << endl;
        else
            cout << start << " -> " << i << " = " << "маршрут недоступен" << endl;
}