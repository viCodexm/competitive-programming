#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;

struct interval {
	int start;
	int end;
};

int main() {
	int n; cin >> n;
	vector<interval> a(n);
	for (int i = 0; i < n; ++i) {
		int h, m, s; int h2, m2, s2;
		scanf_s("%d:%d:%d %d:%d:%d", &h, &m, &s, &h2, &m2, &s2);
		a[i].start = s + m * 60 + h * 3600;
		a[i].end = s2 + m2 * 60 + h2 * 3600;
		if (a[i].start > a[i].end) {
			// добавляем новый интервал от начала дня до конца сна
			a.push_back({ 0, a[i].end });
			// этот сон заканчивает день и прошлым действием переносит новый интервал на следующий день
			a[i].end = 86400;
		}
	}
	sort(a.begin(), a.end(), [](const interval& left, const interval& right) {
		return left.start < right.start;
	});
	int freetime = 0 + a[0].start;
	int prevend = a[0].end;
	n = a.size();
	for (int i = 1; i < n; ++i) {
		// закончился сон, но второй еще не начался
		if (prevend < a[i].start) {
			// свободное время += время до второго сна
			freetime += a[i].start - prevend;
			prevend = a[i].end;
		} else
		// закончился сон, а второй продолжается
		if (prevend < a[i].end) {
			prevend = a[i].end;
		}
		// закончился сон, второй тоже
		// тогда ничего не делаем и идем к следующему
	}
	// если сны закончились, а время еще осталось
	if (prevend < 86400) freetime += 86400 - prevend;
	cout << freetime;
}