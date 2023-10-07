// Thanks a lot to algoteka. The only reliable, readable and simple realisation.
// https://algoteka.com/samples/35/graham-scan-convex-hull-algorithm-c-plus-plus-o%2528n-log-n%2529-readable-solution

// This illustration cotains code for solving CRRC 2023 qualification task K.
// Everything before main can be igonred. Look only on GrahamScan and Point structure.

#include <climits>
#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
#include <stack>

using namespace std;


#define print(v)    for (auto& e : v) cout << e << " "; cout << "\n";
#define read(v)		for (auto& e : v) cin >> e;
typedef long long ll;
typedef vector<int> vi;

struct Point {
    double x;
    double y;

    Point operator-(Point r) {
        return { x - r.x, y - r.y };
    }
    double operator*(Point r) {
        return x * r.x + y * r.y;
    }
    Point rotate90() {  // Rotate 90 degrees counter-clockwise
        return { -y, x };
    }
    double manhattan_length() {
        return abs(x) + abs(y);
    }
    bool operator==(Point r) {
        return x == r.x && y == r.y;
    }
    bool operator!=(Point r) {
        return x != r.x || y != r.y;
    }
};


vector<Point> GrahamScan(std::vector<Point> points) {
    Point first_point = *std::min_element(points.begin(), points.end(), [](Point& left, Point& right) {
        return std::make_tuple(left.y, left.x) < std::make_tuple(right.y, right.x);
    });  // Find the lowest and leftmost point

    sort(points.begin(), points.end(), [&](Point& left, Point& right) {
        if (left == first_point) {
            return right != first_point;
        }
        else if (right == first_point) {
            return false;
        }
        double dir = (left - first_point).rotate90() * (right - first_point);
        if (dir == 0) {  // If the points are on a line with first point, sort by distance (manhattan is equivalent here)
            return (left - first_point).manhattan_length() < (right - first_point).manhattan_length();
        }
        return dir > 0;
        // Alternative approach, closer to common algorithm formulation but inferior:
        // return atan2(left.y - first_point.y, left.x - first_point.x) < atan2(right.y - first_point.y, right.x - first_point.x);
        // Would not recommend using atan2 as it's not accurate.
    });  // Sort the points by angle to the chosen first point

    vector<Point> result;
    for (auto pt : points) {
        // For as long as the last 3 points cause the hull to be non-convex, discard the middle one
        while (result.size() >= 2 &&
            (result[result.size() - 1] - result[result.size() - 2]).rotate90() * (pt - result[result.size() - 1]) < 0) { // be careful '< 0' includes dots on a same line in CH and '<= 0' includes only last one from this line
            result.pop_back();
        }
        result.push_back(pt);
    }
    return result;
}

long long gcd(int a, int b) {
    if (!b)
        return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i)
        cin >> points[i].x >> points[i].y;

    vector<Point> hull = GrahamScan(points);
    long long nPoints = points.size() - hull.size();
    for (int i = 0; i < hull.size() - 1; ++i)
        nPoints -= gcd(abs(hull[i].x - hull[i + 1].x), abs(hull[i].y - hull[i + 1].y)) - 1;

    nPoints -= gcd(abs(hull[0].x - hull[hull.size() - 1].x), abs(hull[0].y - hull[hull.size() - 1].y)) - 1;

    if (nPoints <= 0)
        cout << "YES";
    else cout << abs(nPoints);
    return 0;
}
