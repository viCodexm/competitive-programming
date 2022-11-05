#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <queue>
#include <functional>
 
using namespace std;
 
struct crater {
	int x, y, r, id;
	float dist;
};
 
struct meteor {
	int id;
	float dist;
};
 
bool operator > (const meteor& left, const meteor& right) {
	return left.dist > right.dist;
}
bool operator < (const meteor& left, const meteor& right) {
	return left.dist < right.dist;
}
 
 
bool operator > (const crater& left, const crater& right) {
	return left.dist > right.dist;
}
 
bool operator < (const crater& left, const crater& right) {
	return left.dist < right.dist;
}
 
 
int main() {
	int n; cin >> n;
	priority_queue<meteor, vector<meteor>, std::greater<meteor>> mets;
	for (int i = 0; i < n; ++i) //Метеориты помещаем в очередь, которые сортируются
	{                           // от самого тяжелого к самому легкому
		int mass;
		cin >> mass;
		meteor met;
		met.dist = sqrt(pow(10, 6) / mass);
		met.id = i + 1;
		mets.push(met);
	}
	
	int k; cin >> k;
	priority_queue<crater, vector<crater>, greater<crater>> crats;
	for (int i = 0; i < k; ++i) //Кратеры помещаем в очередь, которые сортируются
	{                           // от самого ближнего к самому дальнему
		crater crat;
		cin >> crat.x >> crat.y >> crat.r;
		crat.dist = sqrt(pow(crat.x, 2) + pow(crat.y, 2)) - crat.r;
		crat.id = i + 1;
		crats.push(crat);
	}
 
	vector<pair<int, int>> ans;
	while ((!mets.empty()) && (!crats.empty())) {
		if (mets.top().dist < crats.top().dist) { //никак не докинуть
			mets.pop();
		}
		else { //докинем - кидаем
			ans.push_back({ mets.top().id, crats.top().id });
			mets.pop();
			crats.pop();
		}
	}
	sort(ans.begin(), ans.end(), [](const pair<int, int>& left, const pair<int, int>& right) {
		return left.first < right.first; //Сортируем метеориты по мере появления
	});
	cout << ans.size() << endl;
	for (auto e : ans) cout << e.first << " " << e.second << endl;
 
	return 0;
}
