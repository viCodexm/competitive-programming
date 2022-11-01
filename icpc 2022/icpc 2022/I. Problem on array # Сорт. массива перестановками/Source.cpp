#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional> // std::less

using namespace std;



int main() {
	
	int n; cin >> n;
	vector<int> input(n);
	priority_queue<int, vector<int>, std::less<int>> ones;
	vector<int> twos;

	for (int i = 0; i < n; ++i) {
		cout << "get " << i + 1 << endl;
		cin >> input[i];
		switch (input[i]) {
		case 1:
			ones.push(i);
			break;
		case 2:
			twos.push_back(i);
			break;
		}

		fflush(stdout);
	}
	//ones, twos упорядочены по возрастанию позиций
	
	// указатель на последний элемент
	int ptr = input.size()-1;
	// указатель на первый элемент в векторе позиций двоек
	int tw = 0;
	if (! twos.empty())
	while (tw < twos.size() && ptr > twos[tw]) {

		// если нашли импостера - свапаем двойку и не двойку
		if (input[ptr] != 2) {
			if (input[ptr] == 1) {
				ones.pop(); // т.к. шли с конца, то встретили последнюю ссылку
				ones.push(twos[tw]); // просто добавим новую ссылку и вау, раз мы добавляем в очердь с приоритетом, то она встанет куда надо
			}
			swap(input[ptr], input[twos[tw]]);
			cout << "swap " << ptr + 1 << " " << twos[tw] + 1 << "\n";
			// сдвигаем указатель на следующую двойку
			tw++;
		}
		// сдвигаем указатель ptr влево
		ptr--;
	}
	vector<int> ones_vec;
	while (!ones.empty()) {
		ones_vec.push_back(ones.top());
		ones.pop();
	}
	reverse(ones_vec.begin(), ones_vec.end());
	// ptr оставляем там же, так как знаем, что справа от него все двойки
	int ow = 0;
	if (!ones_vec.empty())
	while (ow < ones_vec.size() && ptr > ones_vec[ow]) {
		
		if (input[ptr] == 0) { // двоек быть не должно! мы их убрали направо
			swap(input[ptr], input[ones_vec[ow]]);
			cout << "swap " << ptr + 1 << " " << ones_vec[ow] + 1 << "\n";
			ow++;
		}
		ptr--;
	}
	// надеемся, что все работает!

	cout << "Sorted!";
	return 0;
}
