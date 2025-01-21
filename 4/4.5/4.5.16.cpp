
#include <cstdio>

const double EPS = 1e-6;

double binarySearch(double a) {
    double l = -100, r = 100;
    while (r - l > EPS) {
        double mid = (l + r) / 2;
        if (mid * mid * mid + mid * mid + mid - a > 0) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return l;
}

int main() {
    double a;
    scanf("%lf", &a);
    printf("%.2f", binarySearch(a));
    return 0;
}