#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;

struct interval {
	int The_start, The_end; //Начало сна, конец сна
};

int main() {
	int n; cin >> n; //Вводим количество интервалов времени
	vector<interval> a(n); //Сами интервалы времени
	for (int i = 0; i < n; ++i) {
		int h, m, s; int h2, m2, s2;
		scanf("%d:%d:%d %d:%d:%d", &h, &m, &s, &h2, &m2, &s2);
		a[i].The_start = s + m * 60 + h * 3600; //Переводим время в секунды
		a[i].The_end = s2 + m2 * 60 + h2 * 3600;
		if (a[i].The_start > a[i].The_end) { //Если она проснулась в следующий день, то разбиваем интервал на 2
			// добавляем новый интервал от начала следующего дня до конца сна
			a.push_back({ 0, a[i].The_end });
			a[i].The_end = 86400; //сон текущего дня заканчивается в 24:00, т.е. через 86400 сек. от начала текущего дня
		}
	}

    //Сортируем в порядке возрастания моментов начала сна
	sort(a.begin(), a.end(), [](const interval& left, const interval& right) {
		return left.The_start < right.The_start;
	});

	int freetime = 0 + a[0].The_start; //Кол-во свободных секунд соседа для сверления
	int prevend = a[0].The_end; //До скольки она спит
	n = a.size(); //Пересчитываем кол-во интервалов сна
	for (int i = 1; i < n; ++i) {
		// закончился предыдущий сон, но следующий еще не начался
		if (prevend < a[i].The_start) {
			// свободное время += время до следующего сна
			freetime += a[i].The_start - prevend;
			prevend = a[i].The_end; //Устанавливаем указатель на конец следующего сна
		} else
		// начался следующий сон во время предыдущего или впритык к предыдущему
		if (prevend < a[i].The_end) { //Если конец следующего сна дальше конца предыдущего
			prevend = a[i].The_end; //то ставим указатель на конец следующего сна
		}
	}
	// если сны закончились, а время до конца дня еще осталось
	if (prevend < 86400) freetime += 86400 - prevend;
	cout << freetime;
}
