events = []
N = 1
while True:
    try:
        s = input().split()
        s = [s[0], s[2], s[1], s[3], s[4], N]
        events.append(s)
    except:
        break
    N += 1
events.sort()
for s in events:
    print(f"{s[5]} {s[0]} {s[2]}.{s[1]}.2113 {s[3]}:{s[4]}")