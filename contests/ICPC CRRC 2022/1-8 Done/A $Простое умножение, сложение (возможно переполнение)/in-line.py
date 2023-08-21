#python 3.8
print(sum([[a := input().split(), int(a[0])*int(a[1])][1:][0] for i in range(int(input()))]))
