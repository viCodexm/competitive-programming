import math
x1,y1 = map(int,input().split())
x2,y2 = map(int,input().split())
x3,y3 = map(int,input().split())
a = math.sqrt((x1 - x2)**2 + (y1-y2)**2)
b = math.sqrt((x2 - x3)**2 + (y2-y3)**2)
c = math.sqrt((x1 - x3)**2 + (y1-y3)**2)
#Через формулу Герона
r = (a*b*c)/math.sqrt((a+b+c)*(b+c-a)*(c+a-b)*(a+b-c))
print(r)
