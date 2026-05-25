#include <cstdio>
#include <cmath>

struct vector {
    double x, y, z;
    vector():x(),y(),z(){}
    vector(double a, double b, double c) {
        x = a;
        y = b;
        z = c;
    }
    double operator * (vector b) {
        double ans = 0;
        ans += x * b.x;
        ans += y * b.y;
        ans += z * b.z;
        return ans;
    }

    vector operator * (double c) {
        return vector(x * c, y * c, z * c);
    }

    vector operator / (double c) {
        return vector(x / c, y / c, z / c);
    }

    vector operator + (vector b) {
        return vector(x + b.x, y + b.y, z + b.z);
    }
    
    vector operator - (vector b) {
        return vector(x - b.x, y - b.y, z - b.z);
    }

    double len() {
        return sqrt(x * x + y * y + z * z);
    }

    void print() {
        printf("%.6lf %.6lf %.6lf\n", x, y, z);
    }
};

double r;

const double eps = 1e-6;

double dis(vector a, vector b) {
    double tmp = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
    double val = sqrt(tmp) / (2.0 * r);
    val = std::min(1.0, val);
    return 2.0 * asin(val) * r;
}

int gcd(int a, int b) {
    if(b == 0)return std::abs(a);
    return gcd(b, a%b);
}

int main() {
    int T;scanf("%d", &T);
    while(T--) {
        scanf("%lf", &r);
        double a, b, c;
        double len;

        int a1, b1, c1;
        int a2, b2, c2;
        int a3, b3, c3;

        scanf("%d%d%d", &a3, &b3, &c3);
        scanf("%d%d%d", &a1, &b1, &c1);
        scanf("%d%d%d", &a2, &b2, &c2);

        int g1, g2, g3;
        g1 = gcd(gcd(a1, b1), c1);
        g2 = gcd(gcd(a2, b2), c2);
        g3 = gcd(gcd(a3, b3), c3);

        a1 /= g1;b1 /= g1;c1 /= g1;
        a2 /= g2;b2 /= g2;c2 /= g2;
        a3 /= g3;b3 /= g3;c3 /= g3;

        len = sqrt(a1 * a1 + b1 * b1 + c1 * c1);
        vector v1(a1 / len * r, b1 / len * r, c1 / len * r);
        len = sqrt(a2 * a2 + b2 * b2 + c2 * c2);
        vector v2(a2 / len * r, b2 / len * r, c2 / len * r);
        len = sqrt(a3 * a3 + b3 * b3 + c3 * c3);
        vector v3(a3 / len * r, b3 / len * r, c3 / len * r);

        // v1.print();
        // v2.print();
        // v3.print();

        if(a1 == a2 && b1 == b2 && c1 == c2) {
            // printf("---1\n");
            printf("%.18lf\n", dis(v1, v3));
            continue;
        }

        if(a1 == -a2 && b1 == -b2 && c1 == -c2) {
            // printf("---2\n");
            printf("0.0000\n");
            continue;
        }

        if( (a1*a3 + b1*b3 + c1*c3 == 0)&&(a2*a3 + b2*b3 + c2*c3 == 0) ) {
            // printf("---3\n");
            printf("%.18lf\n", dis(v1, v3));
            continue;
        }

        a = v1.y * v2.z - v2.y * v1.z;
        b = v2.x * v1.z - v1.x * v2.z;
        c = v1.x * v2.y - v2.x * v1.y;

        vector n(a, b, c);

        vector ty = v3 - ( (n / n.len()) * (v3 * n / n.len()) );
        len = ty.len();
        ty = ty / len * r;

        // n.print();
        // ty.print();

        double ans;
        double d1 = (ty * v1) / (r * r);
        double d2 = (ty * v2) / (r * r);
        double d12 = (v1 * v2) / (r * r);
        
        double det = 1.0 - d12 * d12;
        
        if (det < 1e-12) {
            ans = std::min(dis(v3, v1), dis(v3, v2));
        } else {
            double c1 = (d1 - d2 * d12) / det;
            double c2 = (d2 - d1 * d12) / det;
            
            if (c1 >= -eps && c2 >= -eps) {
                ans = dis(ty, v3);
            } else {
                ans = std::min(dis(v3, v1), dis(v3, v2));
            }
        }
        
        printf("%.18lf\n", ans);
    }
    return 0;
}