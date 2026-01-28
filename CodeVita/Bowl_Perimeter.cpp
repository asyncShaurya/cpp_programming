#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

// Cross product of OA and OB vectors
long long cross(Point O, Point A, Point B) {
    return (long long)(A.x - O.x) * (B.y - O.y) -
           (long long)(A.y - O.y) * (B.x - O.x);
}

// Distance between two points
double distance(Point a, Point b) {
    return sqrt((double)(a.x - b.x) * (a.x - b.x) +
                (double)(a.y - b.y) * (a.y - b.y));
}

// Convex Hull using Monotone Chain (returns in CCW order)
vector<Point> convexHull(vector<Point> pts) {
    int n = pts.size(), k = 0;
    if (n <= 1) return pts;

    sort(pts.begin(), pts.end(), [](Point a, Point b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });

    vector<Point> hull(2 * n);

    // Lower hull
    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(hull[k-2], hull[k-1], pts[i]) <= 0) k--;
        hull[k++] = pts[i];
    }

    // Upper hull
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && cross(hull[k-2], hull[k-1], pts[i]) <= 0) k--;
        hull[k++] = pts[i];
    }

    hull.resize(k-1);
    return hull;
}

int main() {
    int N;
    cin >> N;
    vector<Point> points(N);

    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> hull = convexHull(points);

    double perimeter = 0;
    for (int i = 0; i < (int)hull.size(); i++) {
        perimeter += distance(hull[i], hull[(i+1) % hull.size()]);
    }

    cout << (int)round(perimeter) << endl;
    return 0;
}
