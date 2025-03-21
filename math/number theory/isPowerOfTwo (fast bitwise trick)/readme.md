
Рассмотрим как работает этот трюк:

Возьмем num = $128_{10} = 10000000_2$

Тогда num & (num-1) будет (10000000 & 01111111) = 0 => false, т.к. ВСЕ позиции не равны. Также num >= 2, поэтому isPowerOfTwo вернет true.

Возьмем num = $127_{10} = 01111111_2$.

Тогда num & (num-1) будет (01111111 & 01111110) != 0 => true, т.к. некоторые позиции совпадают, ответом будет 01111110 = $126_{10}$
и так как 126 != 0 по законам плюсов условие выполнится, и isPowerOfTwo вернет false.

[Задача на эту тему](https://leetcode.com/problems/counting-bits/description/)
