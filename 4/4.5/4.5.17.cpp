#include <cstdio>
#include <cmath>

const double EPS = 1e-6;
const double PI = acos(-1.0);

double f(double R, double h) {
    double alpha = 2 * acos((R - h) / R);
    double L = 2 * sqrt(R * R - (R - h) * (R - h));
    double S1 = alpha * R * R / 2 - L * (R - h) / 2;
    double S2 = PI * R * R / 2;
    return S1 / S2;
}

double binarySearch(double R, double ratio) {
    double l = 0, r = R;
    while (r - l > EPS) {
        double mid = (l + r) / 2;
        if (f(R, mid) > ratio) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return l;
}

int main() {
    double R, r;
    scanf("%lf%lf", &R, &r);
    printf("%.2f", binarySearch(R, r));
    return 0;
}