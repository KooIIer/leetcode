#include <stdio.h>
#include <stdlib.h>

int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize <= 1) { return 0; }
    int t = 0;
    // int x = points[0][0]; int y = points[0][1];
    for (int i = 1; i < pointsSize; i++) { 
        int dx = abs(points[i][0] - points[i-1][0]);
        int dy = abs(points[i][1] - points[i-1][1]);
        if (dx > dy) { t += (dx-dy)+dy; }
        else { t += (dy-dx)+dx; }
        /*while (dx != 0 || dy != 0) {
            if (dx != 0) { x += dx/abs(dx); dx -= dx/abs(dx); }
            if (dy != 0) { y += dy/abs(dy); dy -= dy/abs(dy); }
            t++;
        }*/
    }
    return t;
}

int main() {
    int* points[] = {(int[]){1,1},(int[]){3,4},(int[]){-1,0}};
    printf("%d\n", minTimeToVisitAllPoints(points, 3, (int[]){2,2,2}));
    
    return 0;
}
