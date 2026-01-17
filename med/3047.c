#include <math.h>
#include <stdio.h>

long long largestSquareArea(int** bottomLeft, int bottomLeftSize, int* bottomLeftColSize, int** topRight, int topRightSize, int* topRightColSize) {
    int n = bottomLeftSize;
    long long r = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) { continue; }
            if (bottomLeft[i][0] >= topRight[j][0]) { continue; }
            if (bottomLeft[i][1] >= topRight[j][1]) { continue; }
            if (bottomLeft[j][0] >= topRight[i][0]) { continue; }
            if (bottomLeft[j][1] >= topRight[i][1]) { continue; }
            int x0 = fmax(bottomLeft[i][0], bottomLeft[j][0]);
            int x1 = fmin(topRight[i][0], topRight[j][0]);
            int y0 = fmax(bottomLeft[i][1], bottomLeft[j][1]);
            int y1 = fmin(topRight[i][1], topRight[j][1]);

            int s = fmin(x1-x0,y1-y0);

            // printf("x0 %d x1 %d y0 %d y1 %d; x1-x0 %d y1-y0 %d\n", x0,x1,y0,y1,x1-x0,y1-y0);

            long long a = (long long)s*s;

            // if (s0 != s1) { continue; }
            // long long s = s0*s1;
            r = (a > r) ? a : r;
        }
    }

    return r;
}

int main() {
    int bl[3][2] = {{1,1},{2,2},{3,1}};
    int tr[3][2] = {{3,3},{4,4},{6,6}};
    printf("%lld\n", largestSquareArea((int*[]){bl[0],bl[1],bl[2]}, 3, (int[]){2,2,2}, (int*[]){tr[0],tr[1],tr[2]}, 3, (int[]){2,2,2}));
    return 0;
}
