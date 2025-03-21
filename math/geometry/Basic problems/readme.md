https://habr.com/ru/post/147691/

1. Проверка существования треугольника с заданными сторонами
  
      *Треугольник задан длинами сторон - проверяем, что каждая сторона больше суммы двух оставшихся сторон (достаточное условие);
      
      *Треугольник задан координатами вершин - треугольник не существует только тогда, когда все три точки лежат на одной линии - косое(псевдоскалярное) произведение двух векторов, лежащих на смежных сторонах не должно быть равно 0 (если равно 0, то векторы коллинеарны и треугольника - нет)
           
<p align="center">
  <img src="Существование треугольника.jpg" width="660"/>
</p>

2. Определить тип треугольника: остроугольный, прямоугольный или тупоугольный

      *Треугольник задан длинами сторон - напротив большей стороны лежит больший угол. Выбираем наибольшую сторону треугольника (обозначим ее за a, остальные стороны b и c). Тогда:
      
          Если cosα > 0, то a2 < b2 + c2 – треугольник остроугольный
          
          Если cosα = 0, то a2 = b2 + c2 – треугольник прямоугольный
          
          Если cosα < 0, то a2 > b2 + c2 – треугольник тупоугольный
          
<p align="center">
  <img src="Теорема косинусов.jpg" width="660"/>
</p>

      *Треугольник задан координатами вершин - считаем скалярное произведение каждой пары векторов, лежащих на смежных сторонах (координата начала обоих векторов - их общая вершина), затем перемножаем. Тогда:
      
          Если результат = 0, то треугольник прямоугольный, т.к. cos одного из углов дал 0
          
          Если результат со знаком +, то треугольник остроугольный, т.к. косинусы всех углов такого треугольника положительны;
          
          Если результат со знаком -, то треугольник тупоугольный, т.к. один из косинусов со знаком минус (в тупоугольном треугольнике есть только одний тупой угол) 
      
3. По данным сторонам треугольника найти его площадь.

      *Треугольник задан длинами сторон - формула Герона - S = sqrt(p(p-a)(p-b)(p-c)), где p = (a+b+c)/2 - полупериметр
      
      *Треугольник задан координатами вершин - находим половину от косого произведения (либо от определителя матрицы) двух векторов, лежащих на смежных сторонах (координата начала обоих векторов - их общая вершина)
      
4. Дана точка и треугольник заданный координатами своих вершин. Определить лежит ли точка внутри, на границе или вне этого треугольника.

      *Метод площадей (неэффективный) - пусть ABC - треугольник, K - произвольная точка. Если сумма площадей треугольников AKB, AKC, BKC больше площади треугольника ABC точка лежит вне треугольника. Если же сумма первых трех площадей равна четвертой, то нужно проверить, не равна ли нулю одна из трех площадей. Если равна, то точка лежит на границе треугольника, иначе – внутри. Вычислять площади треугольников, естественно, надо через косое произведение векторов.
      
      *Проверка полуплоскостей (эффективный) - если хотя бы одна из сторон треугольника «разводит» противолежащую ей вершину и точку по разным полуплоскостям, то точка лежит вне треугольника. Иначе, если точка принадлежит хотя бы одной из прямых, содержащих стороны треугольника, то она находится на границе треугольника. Иначе точка лежит внутри треугольника.
      Вычисляем косое произведение и сравниваем знаки (расписано на хабре) ...
      
5. Вычисление площади многоугольника заданного координатами своих вершин.
