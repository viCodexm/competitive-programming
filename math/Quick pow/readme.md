# Бинарное возведение в степень:

$3^{11} = 3^1 * 3^2 * 3^8$

$3^{12} = 3^4 * 3^8$

# Рекурсией: $a^b = (a^{b/2})^2$
```cpp
int power(int a, int b) {
    if (b == 0) return 1;
    int tmp = power(a, b / 2);
    int result = tmp * tmp;
    if (b % 2 == 1) result *= a;
    return result;
}
```