n, k = (int(i) for i in input().split())
quotient, remainder = divmod(n, 4)
step = ((n - 1) // 4) % 4
if remainder:
    new_number = (k - 1 - step) % 4 + 1
    if new_number <= remainder:
        quotient += 1
print(quotient)