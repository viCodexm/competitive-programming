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
int main() {
    std::cin.tie(0);
    ios_base::sync_with_stdio(false);
}
```
## Перенаправление stdin/stdout в файлы
```c++
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
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
