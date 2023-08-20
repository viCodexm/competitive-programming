#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	int n1, n2, m1, m2;
	cin >> n1 >> n2 >> m1 >> m2;

	set<string> w1; set<string> w2;
	set<string> b;

	string s;
	for (int i = 0; i < n1; ++i) { //Вводим имена, которые нравятся Игорю WhiteList
		cin >> s;
		w1.insert(s);
	}
	for (int i = 0; i < n2; ++i) { //Вводим имена, которые нравятся Ире WhiteList
		cin >> s;
		w2.insert(s);
	}
	
	set <string> w;
	for (auto a : w1) //Ищем пересечение множеств n1 и n2
		for (auto b : w2)            //, т.е. имена, которые нравятся и Игорю и Ире
			if (a == b) { //Если имена из WhiteList Игоря совпадают с именами из WhiteList Иры
				w.insert(a);                      //, то добавляем их в общий WhiteList
				break;
			}

	for (int i = 0; i < m1 + m2; ++i) { //Заполняем общий BlackList
		cin >> s;
		b.insert(s);
	}

	set<string> ans; //Имена, которые есть в WhiteList, но нет в BlackList
	for (auto e : w) {
		if (b.count(e) == 0) //Если в BlackList нет имени из WhiteList, то пишем в ответ
			ans.insert(e); //Имя из WhiteList
	}
	//Имена на выходе уже отсортированы в алфавитном порядке, т.к. set их сам сортирует
	for (auto e : ans) { //Выводим имена в алфавитном порядке, которые удовлетворяют условию задачи 
		cout << e << endl;
	}
}
