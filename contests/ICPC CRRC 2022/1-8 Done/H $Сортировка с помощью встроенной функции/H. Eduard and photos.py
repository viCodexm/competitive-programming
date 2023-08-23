events, N = [], 1
for s in open(0):
    s = s.split()
    events.append([s[0], s[2], s[1], s[3], s[4], N])
    N += 1
events.sort()
for s in events:
    print(f"{s[5]} {s[0]} {s[2]}.{s[1]}.2113 {s[3]}:{s[4]}")
