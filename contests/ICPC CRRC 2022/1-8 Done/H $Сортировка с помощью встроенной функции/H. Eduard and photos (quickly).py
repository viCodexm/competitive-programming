for s in sorted((a:=i.split(), a[0], a[2], a[1], a[3], a[4], ind)[1:] for ind, i in enumerate(open(0).readlines(), 1)):
    print(f"{s[5]} {s[0]} {s[2]}.{s[1]}.2113 {s[3]}:{s[4]}")