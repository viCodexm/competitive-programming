n, k, m = (int(i) for i in input().split())
res = 0
while k and n:
    res += m
    m += 1
    n -= 1
    k -= 1
print(res)