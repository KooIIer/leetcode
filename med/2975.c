//результаты оч плохие, но ладно
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cm(const void* a, const void* b) {
    return *(int*)a-*(int*)b;
}

int maximizeSquareArea(int m, int n, int* hFences, int hFencesSize, int* vFences, int vFencesSize) {
    const int hl = hFencesSize+2;
    const int vl = vFencesSize+2;
    // int h[hFencesSize+2];
    // int v[vFencesSize+2];
    int* h = malloc(sizeof(int)*(hl));
    int* v = malloc(sizeof(int)*(vl));
    v[0] = h[0] = 1;
    h[1] = m;
    v[1] = n;
    memcpy(h+2, hFences, sizeof(int)*hFencesSize);
    memcpy(v+2, vFences, sizeof(int)*vFencesSize);

    qsort(h, hl, sizeof(int), cm);
    qsort(v, vl, sizeof(int), cm);

    /*for (int i = 0; i < hl; i++) {
        printf("%d\n", h[i]);
    }*/

    const int hdl = hl*(hl-1)/2;
    const int vdl = vl*(vl-1)/2;

    int* hd = malloc(sizeof(int)*hdl);
    int* vd = malloc(sizeof(int)*vdl);

    int c = 0;
    for (int i = 0; i < hl; i++) {
        for (int j = i+1; j < hl; j++) {
            hd[c++] = h[j] - h[i];
        }
    }
    c = 0;
    for (int i = 0; i < vl; i++) {
        for (int j = i+1; j < vl; j++) {
            vd[c++] = v[j] - v[i];
        }
    }

    qsort(hd, hdl, sizeof(int), cm);
    qsort(vd, vdl, sizeof(int), cm);

    int r = -1;

    for (int i = hdl-1; i >= 0; i--) {
        int t = hd[i];
        int mn = 0;
        int mx = vdl-1;
        while (1) {
            if (mx < mn) { break; }
            int p = mn+(mx-mn)/2;
            // printf("t %d; p %d; mn %d; mx %d\n", t, p, mn, mx);
            // if (vd[p] == t) { return t; }
            if (vd[p] == t) { r = t; break; }
            if (vd[p] > t) { mx = p-1; }
            else { mn = p+1; }
        }
        if (r != -1) { break; }
    }
    // printf("%d\n", r%(int)(1e9+7));
    free(h);
    free(v);
    free(hd);
    free(vd);
    // return (r==-1) ? -1 : (r*r)%(int)(1e9+7);
    // return (r==-1) ? -1 : (r*r)%(long long)(1e9+7);
    if (r == -1) { return -1; }
    long long t = r;
    t *= t;
    return t%(long long)(1e9+7);
}

int main() {
    // printf("%d\n", maximizeSquareArea(4, 3, (int[]){2,3}, 2, (int[]){2}, 1));
    printf("%d\n", maximizeSquareArea(6, 7, (int[]){2}, 1, (int[]){4}, 1));
    return 0;
}
