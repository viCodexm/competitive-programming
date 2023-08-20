n, k, m = (int(i) for i in input().split())
ans = 1
if not k:
    ans = 0
elif m < n and n !=k:
    probability_not_knight = 1
    for i in range(0, m):
        probability_not_knight *= (n - k - i) / (n - i)
    ans = 1 - probability_not_knight
print(ans)