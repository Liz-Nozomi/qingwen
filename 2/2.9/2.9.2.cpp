
#include <cstdio>
#include <cmath>

const double EPS = 1e-8;

bool greater(double a, double b) {
    return a - b > EPS;
}

bool less(double a, double b) {
    return a - b < -EPS;
}

int main() {
    double a, b, c, d;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    double result1 = a * asin(sqrt(b) / 2);
    double result2 = c * asin(sqrt(d) / 2);
    if (greater(result1, result2)) {
        printf("1");
    } else if (less(result1, result2)) {
        printf("2");
    } else {
        printf("0");
    }
    return 0;
}//建议使用python