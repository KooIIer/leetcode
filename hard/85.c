#include <math.h>
#include <stdio.h>
#include <string.h>

int s(int* line, int l) {
    //медленно, но работает
    int m = 0;
    for (int i = 0; i < l; i++) {
        int h = line[i];
        if (h == 0) { continue; }
        int a = h;
        for (int j = i+1; j < l; j++) {
            if (j >= l) { break; }
            if (line[j] < h) { break; }
            a += h;
        }
        for (int j = i-1; j >= 0; j--) {
            if (j < 0) { break; }
            if (line[j] < h) { break; }
            a += h;
        }
        // printf("%d\n", i);
        m = (int)fmax(m, a);
    }
    /*if (m == 4) {
        printf("%d %d %d %d %d\n", line[0], line[1], line[2], line[3], line[4]);
    }*/
    return m;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    // printf("%d %d\n", matrixSize, matrixColSize[0]);
    int m = 0;
    int line[matrixColSize[0]];
    memset(line, 0, matrixColSize[0]*sizeof(int));
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            // printf("%c", matrix[i][j]);
            if (matrix[i][j] == '0') {
                line[j] = 0;
            } else {
                line[j]++;
            }
        }
        // printf("%d %d %d %d %d\n", line[0], line[1], line[2], line[3], line[4]);
        // printf("\n");
        m = (int)fmax(m, s(line, matrixColSize[0]));
    }
    return m;
}

int main() {
    char* matrix[] = {(char[]){'1','0','1','0','0'},(char[]){'1','0','1','1','1'},(char[]){'1','1','1','1','1'},(char[]){'1','0','0','1','0'}};
    int cols[4] = {5,5,5,5};
    printf("\n%d\n", maximalRectangle(matrix, 4, cols));
    return 0;
}
