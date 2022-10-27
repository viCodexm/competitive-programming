
//http://e-maxx.ru/algo/dijkstra
//O(n^2+m) 

const int INF = 1000000000;
 
int main() {
	int n;
	... чтение n ...
	vector < vector < pair<int,int> > > g (n);
	... чтение графа ...
	int s = ...; // стартовая вершина
 
	vector<int> d (n, INF),  p (n);
	d[s] = 0;
	vector<char> u (n);
	for (int i=0; i<n; ++i) {
		int v = -1;
		for (int j=0; j<n; ++j)
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		if (d[v] == INF)
			break;
		u[v] = true;
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
			}
		}
	}
}
//Восстановить путь до любой вершины t можно следующим образом:

vector<int> path;
for (int v=t; v!=s; v=p[v])
	path.push_back (v);
path.push_back (s);
reverse (path.begin(), path.end());