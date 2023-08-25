x1, y1, x2, y2, x3, y3 = (int(i) for i in open(0).read().split())
a = abs(complex(x1, y1) - complex(x2, y2))
b = abs(complex(x2, y2) - complex(x3, y3))
c = abs(complex(x1, y1) - complex(x3, y3))
r = (a*b*c)/ ((a+b+c)*(b+c-a)*(c+a-b)*(a+b-c)) ** 0.5
print(r)