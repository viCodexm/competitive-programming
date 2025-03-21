Для решения задачи по вероятности, нужно знать следующую информацию:

Количество фишек в мешке у Игоря (n)
Количество рыцарей среди фишек в мешке (k)
Количество фишек, которые Игорь вытаскивает (m)
Вероятность события, что Игорь вытащит хотя бы одного рыцаря, можно выразить через противоположное событие - вероятность того, что Игорь не вытащит ни одного рыцаря.

Вероятность, что Игорь вытаскивает фишку, не являющуюся рыцарем, на первом ходу, равна (n-k)/(n).

Следовательно, вероятность, что Игорь не вытаскивает ни одного рыцаря во время своего хода, равна (n-k)/(n) * (n-k-1)/(n-1) * ... * (n-k-m+1)/(n-m+1).

Тогда вероятность того, что Игорь вытащит хотя бы одного рыцаря, будет равна:

1 - (n-k)/(n) * (n-k-1)/(n-1) * ... * (n-k-m+1)/(n-m+1)

Вычислив это выражение, получаем искомую вероятность.