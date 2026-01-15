#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int cm(const void* a, const void* b) {
    return *(int*)a-*(int*)b;
}

int maximizeSquareHoleArea(int n, int m, int* hBars, int hBarsSize, int* vBars, int vBarsSize) {
    qsort(hBars, hBarsSize, sizeof(int), cm);
    qsort(vBars, vBarsSize, sizeof(int), cm);

    /*for (int i = 0; i < hBarsSize; i++) {
        printf("h %d\n", hBars[i]);
    }
    for (int i = 0; i < vBarsSize; i++) {
        printf("v %d\n", vBars[i]);
    }*/

    int m0 = 1; int m1 = 1;
    int c = 1;
    for (int i = 1; i < hBarsSize; i++) {
        if (hBars[i] != hBars[i-1]+1) { c = 1; }
        else { c++; }
        m0 = fmax(m0, c);
    }
    c = 1;
    for (int i = 1; i < vBarsSize; i++) {
        if (vBars[i] != vBars[i-1]+1) { c = 1; }
        else { c++; }
        m1 = fmax(m1, c);
    }

    return pow(1+fmin(m0,m1),2);
}

int main() {
    printf("%d\n", maximizeSquareHoleArea(2, 1, (int[]){2,3}, 2, (int[]){2}, 1));

    return 0;
}
