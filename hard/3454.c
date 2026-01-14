//686/763, Time Limit Exceeded...

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmi(const void* a, const void* b) {
    const double* ia = (const double*)a;
    const double* ib = (const double*)b;

    if (ia[0] < ib[0]) { return -1; }
    if (ia[0] > ib[0]) { return 1; }
    if (ia[1] < ib[1]) { return -1; }
    if (ia[1] > ib[1]) { return 1; }
    return 0;
}

double ci(double* is, int l) {
    double r = 0;
    
    if (l == 0) { return 0; }
    
    qsort(is, l, sizeof(double)*2, cmi);

    double mn = is[0]; double mx = is[1];
    for (int i = 1; i < l; i++) {
        double mni = is[i*2];
        double mxi = is[i*2+1];

        if (mni <= mx) { mx = fmax(mx, mxi); }
        else {
            r += mx-mn;
            mn = mni;
            mx = mxi;
        }
    }
    r += mx-mn;
    return r;
}

int cm(const void* a, const void* b) {
    double ad = *(const double*)a;
    double bd = *(const double*)b;
    if (ad > bd) { return 1; }
    if (ad < bd) { return -1; }
    return 0;
}

double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
    double p = 1e-5;

    double ymin, ymax;
    for (int i = 0; i < squaresSize; i++) {
        if (i == 0 || squares[i][1] < ymin) { ymin = squares[i][1]; }
        if (i == 0 || squares[i][1]+squares[i][2] > ymax) { ymax = squares[i][1] + squares[i][2]; }
    }
    
    printf("%d; %.2f - %.2f\n", squaresSize, ymin, ymax);

    double* xs = malloc(squaresSize*2*sizeof(double));
    int xl = 0;
    for (int i = 0; i < squaresSize; i++) {
        double l = squares[i][0];
        double r = squares[i][0] + squares[i][2];
        bool g = 0;

        for (int j = 0; j < xl; j++) {
            if (fabs(xs[j]-l) < p) { g = 1; break; }
        }
        if (!g) { xs[xl++] = l; }
        g = 0;

        for (int j = 0; j < xl; j++) {
            if (fabs(xs[j]-r) < p) { g = 1; break; }
        }
        if (!g) { xs[xl++] = r; }
    }

    qsort(xs, xl, sizeof(double), cm);

    double* isa = malloc(squaresSize*2*sizeof(double));
    double* isb = malloc(squaresSize*2*sizeof(double));

    // printf("min %.1f; max %.1f; sh %.1f\n", ymin, ymax, sh);
    double y;
    while (fabs(ymax - ymin) > p) {
        y = (double)(ymax+ymin)/2;
        // printf("%.1f \n", y);
        double sa = 0; double sb = 0;

        for (int i = 0; i < xl-1; i++) {
            double x0 = xs[i];
            double x1 = xs[i+1];

            if (x1-x0 < p) { continue; }

            // double* isa = malloc(squaresSize*2*sizeof(double));
            // double* isb = malloc(squaresSize*2*sizeof(double));
            int ca = 0; int cb = 0;

            for (int j = 0; j < squaresSize; j++) {
                double xi = squares[j][0];
                double yi = squares[j][1];
                double li = squares[j][2];
                
                if (xi <= x0 && xi+li >= x1) {
                    if (yi+li > y) {
                        double t = fmax(y,yi);
                        if (t < yi+li) {
                            isa[ca*2] = t;
                            isa[ca*2+1] = yi+li;
                            ca++;
                        }
                    }

                    if (yi < y) {
                        double t = fmin(y,yi+li);
                        if (yi < t) {
                            isb[cb*2] = yi;
                            isb[cb*2+1] = t;
                            cb++;
                        }
                    }
                }
            }

            double ya = ci(isa, ca);
            double yb = ci(isb, cb);

            sa += ya*(x1-x0);
            sb += yb*(x1-x0);
        
            // free(isa);
            // free(isb);
        }

        if (sa > sb + 1e-9) {
            ymin = y;
        } else {
            ymax = y;
        }
    }
    free(isa);
    free(isb);
    free(xs);
    return y;
}

int main() {
    int* squares[] = {(int[]){0,0,1},(int[]){2,2,1}};
    printf("\n%.5f\n", separateSquares(squares, 2, (int[]){3,3}));
    
    return 0;
}
