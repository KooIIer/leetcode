#include <math.h>
#include <stdio.h>

double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
    double ymin, ymax;
    double sh = 0;
    for (int i = 0; i < squaresSize; i++) {
        sh += (double)squares[i][2]*squares[i][2]/2;
        if (i == 0 || squares[i][1] < ymin) { ymin = squares[i][1]; }
        if (i == 0 || squares[i][1]+squares[i][2] > ymax) { ymax = squares[i][1] + squares[i][2]; }
    }
    // printf("min %.1f; max %.1f; sh %.1f\n", ymin, ymax, sh);
    double y;
    while (fabs(ymax - ymin) > 1e-5) {
        y = (double)(ymax+ymin)/2;
        // printf("%.1f \n", y);
        double sa = 0;
        for (int i = 0; i < squaresSize; i++) {
            double si = (squares[i][1]+squares[i][2]-fmax(squares[i][1], y)) * squares[i][2];
            if (si > 0) { sa += si; }
        }
        if (sa > sh) {
            ymin = y;
        } else {
            ymax = y;
        }
    }
    return y;
}

int main() {
    // int* squares[] = {(int[]){0,0,1},(int[]){2,2,1}};
    int* squares[] = {(int[]){0,0,2},(int[]){1,1,1}};
    printf("\n%.5f\n", separateSquares(squares, 2, (int[]){3,3}));
    
    return 0;
}
