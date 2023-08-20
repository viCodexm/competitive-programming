A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]
C = [int(i) for i in input().split()] 
 
AB = (B[0] - A[0], B[1] - A[1])
AC = (C[0] - A[0], C[1] - A[1])
BC = (C[0] - B[0], C[1] - B[1])
 
side_a = (BC[0] ** 2 + BC[1] ** 2) ** 0.5
side_b = (AC[0] ** 2 + AC[1] ** 2) ** 0.5
side_c = (AB[0] ** 2 + AB[1] ** 2) ** 0.5
 
sin_alpha = (AB[0] * AC[1] - AB[1] * AC[0]) / (side_b * side_c)
print(side_a / (2 * abs(sin_alpha)))