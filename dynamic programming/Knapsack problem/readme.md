# Задача о рюкзаке
Задача о рюкзаке (Knapsack problem) — дано **N** предметов, $n_i$ предмет имеет массу $w_i > 0$ и стоимость $p_i > 0$. Необходимо выбрать из этих предметов такой набор, чтобы суммарная масса не превосходила заданной величины **W** (вместимость рюкзака), а суммарная стоимость была максимальна

---
## Асимптотика
Время и память: O(N*W)

---

## Решение с помощью динамики
[Хорошо разобрано здесь](https://neerc.ifmo.ru/wiki/index.php?title=Задача_о_рюкзаке)

[Видео с объяснением 1](https://www.youtube.com/watch?v=d1A_PKLlJIE)

[Видео с объяснением 2](https://www.youtube.com/watch?v=S2eVYez_j58)

```c++
int knapsackWeight, nItems;
cin >> knapsackWeight >> nItems;

vector<int> weights(nItems, 0), costOfItems(nItems, 0);
for (auto& x : weights)
    cin >> x;
for (auto& x : costOfItems)
    cin >> x;

vector<vector<int>> dp(nItems + 1, vector<int>(knapsackWeight + 1, 0));    

for (int k = 0; k < nItems; ++k)
    for (int s = 1; s <= knapsackWeight; ++s)
        if (s >= weights[k])
            dp[k + 1][s] = max(dp[k][s], dp[k][s - weights[k]] + costOfItems[k]);
        else
            dp[k + 1][s] = dp[k][s];

cout << dp[nItems][knapsackWeight];
```
```
Input:
13 5
3 4 5 8 9
1 6 4 7 6

Output:
13
```

[Уменьшение памяти до O(W) (решение внизу)](https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/)

