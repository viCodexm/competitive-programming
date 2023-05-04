Включить максимальную оптимизацию у компилятора

#pragma GCC optimize("-Ofast", "unroll-loops")


Включить все библиотеки в файл (работает только у GCC)

#include <bits/stdc++.h>

Увеличить скорость ввода/вывода библиотеки <iostream>

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
}