import matplotlib.pyplot as plt

def get_slope(p1, p2):
    if p1[0] == p2[0]:
        return float('inf')
    else:
        return 1.0 * (p1[1] - p2[1]) / (p1[0] - p2[0])

def sort_points(points, start):
    return sorted(points, key=lambda p: (get_slope(p, start), -p[1], p[0]))

def orientation(p, q, r):
    val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1])
    if val > 0:
        return 1  # clockwise
    elif val < 0:
        return 2  # counterclockwise
    else:
        return 0  # collinear

def graham_scan(points):
    points.sort(key=lambda x: [x[0], x[1]])
    start = points.pop(0)
    points = sort_points(points, start)
    hull = [start, points.pop(0)]
    for point in points:
        while orientation(hull[-2], hull[-1], point) != 2:
            hull.pop()
        hull.append(point)
    return hull



def plot_graph(points, hull):
    plt.figure()
    xs, ys = zip(*points)
    plt.scatter(xs, ys)
    for i in range(1, len(hull)):
        plt.plot((hull[i-1][0], hull[i][0]), (hull[i-1][1], hull[i][1]), 'b')
    plt.plot((hull[0][0], hull[-1][0]), (hull[0][1], hull[-1][1]), 'b')
    plt.show()


    
import random

points = [(random.randint(0, 100), random.randint(0, 100)) for _ in range(50)]
hull = graham_scan(points[:])
plot_graph(points, hull)