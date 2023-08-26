## Включить максимальную оптимизацию у компилятора
```c++
#pragma GCC optimize("-Ofast", "unroll-loops")
```
## Включить все библиотеки в файл (работает только у GCC)
```c++
#include <bits/stdc++.h>
```
## Увеличить скорость ввода/вывода библиотеки iostream
```c++
ios_base::sync_with_stdio(0);
std::cin.tie(0);    
```

<details>
<summary>Объяснение</summary>

Первая команда отключает синхронизацию **iostreams с stdio**. По умолчанию она включена, то есть, **iostreams и stdio** можно использовать вместе. После отключения синхронизации так делать больше нельзя, однако за счёт этого **iostreams** может работать быстрее.

По умолчанию cout привязан к **cin**, что означает, что при каждой операции над **cin** вызывается **cout.flush()**. Это сделано, чтобы такой код работал нормально:

cout << "Enter your name: "; //Сначало выводится это

cin >> name; //После запрашиваются данные. А не наоборот

Чтобы отключить привязку и повысить производительность, надо вызвать **cin.tie(0)**;

На производительность **iostreams** негативно влияет частое использование **endl**, поскольку **endl** не только выводит символ новой строки, но и сбрасывает буфер **stdout**. Вместо **endl** можно просто выводить **"\n"**.

[Про cout.tie(0) (Спойлер: бесполезная вещь)](https://codeforces.com/blog/entry/90775)

</details>

## Перенаправление stdin/stdout в файлы
```c++
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
```
## Замер времени работы кода
```c++
#include <chrono>
int main() {
  auto begin = std::chrono::steady_clock::now(); //Старт
  //Ваш код 
  auto end = std::chrono::steady_clock::now(); //Конец
  auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
  std::cout << "The time: " << elapsed_ms.count() << " ms\n";
}
```
