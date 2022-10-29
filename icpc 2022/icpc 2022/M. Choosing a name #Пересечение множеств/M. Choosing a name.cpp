#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
 
using namespace std;
 
int main() {
	int n1, n2, m1, m2;
	cin >> n1 >> n2 >> m1 >> m2;
 
	set<string> w1; set<string> w2;
	set<string> b;
 
	string s;
	for (int i = 0; i < n1; ++i) {
		cin >> s;
		w1.insert(s);
	}
	for (int i = 0; i < n2; ++i) {
		cin >> s;
		w2.insert(s);
	}
	set <string> w;
	for (auto a : w1)
		for (auto b : w2)
			if (a == b) {
				w.insert(a);
				break;
			}
 
	for (int i = 0; i < m1 + m2; ++i) {
		cin >> s;
		b.insert(s);
	}
 
 
	
	set<string> ans;
	for (auto e : w) {
		
		if (b.count(e) == 0)
			ans.insert(e);
	}
 
	for (auto e : ans) {
		cout << e << endl;
	}

}