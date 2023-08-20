<h1>Сумма попарных произведений массива</h1>
<h2>Без модуля</h2>

```python
def sumProductsOfPairs(lst):
    total = psum = 0
    for x in lst:
        total += psum * x
        psum += x
    return total
```
<h2>По модулю</h2>

```python
def sumProductsOfPairs(lst):
    total = psum = 0
    for x in lst:
        total += psum * x
        psum += x
        total %= module
        psum %= module
    return total % module
```