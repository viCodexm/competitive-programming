alphabet=[str(i) for i in range(10)]+list('abcdefghijklmnopqrstuvwxyz')
def num_to_normal(base,num):
    x=0
    p=len(num)-1
    for i in num:
        x+=alphabet.index(i.lower())*base**p
        p-=1
    return x
num1,num2,res=input(), input(), input()
bases=[]
for i in range(2,37):
    a=num_to_normal(i,num1)
    b = num_to_normal(i, num2)
    c = num_to_normal(i, res)
    if (a+b==c):
        bases.append(i)
            
if len(bases)==1:
    print(bases[0])
else: print(0)