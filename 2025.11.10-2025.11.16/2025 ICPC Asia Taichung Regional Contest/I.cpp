#include <bits/stdc++.h>
using namespace std;
struct Point {
    long long x, y;
    Point(long long x = 0, long long y = 0) : x(x), y(y) {}
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }
};
double cross(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}
double dist(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
Point pivot; 
bool polarCompare(const Point& a, const Point& b) {
    double cr = cross(a - pivot, b - pivot);
    if (cr != 0) return cr > 0;
    return dist(pivot, a) < dist(pivot, b);
}
vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n <= 1) return points;
    sort(points.begin(), points.end());
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[minIndex].y || (points[i].y == points[minIndex].y && points[i].x < points[minIndex].x))
            minIndex = i;
    }
    swap(points[0], points[minIndex]);
    pivot = points[0];
    sort(points.begin() + 1, points.end(), polarCompare);
    vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    for (int i = 2; i < n; i++) {
        while (hull.size() >= 2) {
            Point a = hull[hull.size() - 2]; 
            Point b = hull[hull.size() - 1];
            Point c = points[i];            
            if (cross(b - a, c - a) > 0) break;
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    return hull;
}
bool check(const Point& p, const vector<Point>& hull) {
    int n = hull.size();
    for (int i = 0; i < n; ++i) {
        Point a = hull[i];
        Point b = hull[(i + 1) % n];
        if (cross(b - a, p - a) <= 0) {
            return false;
        }
    }
    return true;
} 
vector<Point> p;
int n;
double r,ans;
const double pi = 3.141592653589793;
void solve(const vector<Point>& hull) {
    int n = hull.size();
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        Point a = hull[i];
        Point b = hull[(i + 1) % n];
        long long A, B, C;
        A = (b.y - a.y), B = (a.x - b.x), C = cross(a, b);
        double d = 1.0 * abs(C) / sqrt(A * A + B * B);
        double theta = 2.0 * acos(d / r); 
        double s = 0.5 * r * r * theta;
        double arc = s - d * sqrt(r * r - d * d);
        ans = max(ans, arc);
    }
    cout << setprecision(15) << ans;
    return ;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r;
    for(int i = 1; i <= n; i++){
        long long x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }
    vector<Point> hull = convexHull(p);
    if(!check({0, 0},hull)){
        cout << setprecision(15) << 0.5 * r * r * pi;
        return 0;
    }
    solve(hull);
    return 0;
}