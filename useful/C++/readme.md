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
