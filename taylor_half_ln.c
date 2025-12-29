#include <stdio.h>
#include <math.h>

int main(void) {
    double a = 0.2, b = 0.7;
    int n = 10;
    double eps = 1e-15;
    int max_iter = 1000;

    printf("a = %.2f, b = %.2f\n\n", a, b);
    printf("   x      partial_sum(Series)     0.5*ln(x)    iter    abs_error\n");
    printf("----------------------------------------------------------------\n");

    for (int i = 0; i <= n; ++i) {
        double x = a + (b - a) * ((double)i / n);

        double t = (x - 1.0) / (x + 1.0);
        double pow_t = t;
        double s = 0.0;
        int iter = 0;

        for (int k = 0; k < max_iter; ++k) {
            double term = pow_t / (2*k + 1);
            s += term;
            iter = k + 1;
            if (fabs(term) < eps) break;
            pow_t *= t * t;
        }

        double exact = 0.5 * log(x);
        double err = fabs(s - exact);

        printf("%6.4f   %20.16f   %12.10f   %4d   %13.6e\n",
               x, s, exact, iter, err);
    }
    return 0;
}