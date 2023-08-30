# Основные алгоритмы в теории чисел (Python)

### Поиск  всех делителей числа за **O($\sqrt{N}$)**

```python
n = 36
allDivisors = [] 
for i in range(1, int(n ** 0.5)):
    d, q = divmod(n, i)
    if q == 0:
        allDivisors.extend([i, d])
else:
    i += 1
    d, q = divmod(n, i)
    if q == 0:
        if i != d:
            allDivisors.append(d)
        allDivisors.append(i)
print(sorted(allDivisors))
```

<details>
<summary>Объяснение</summary>

Пользуемся тем, что делители числа N симметричны относительно $\sqrt{N}$. (делители располагаются парами). Если мы узнали, что  10 / 5 = 2, то мы можем записать сразу два делителя для числа 10: 5 и 10 / 5, т.е. 2. 
</details>

### Разложение числа на простые множители
```python
def factorize(n: int) -> list[int]:
    if n == 1:
        return []
    fact, i = [], 2
    while i * i <= n:
        while n % i == 0:
            fact.append(i)
            n //= i
        i += 1
    return fact + [n]

print(factorize(2342352355))
```