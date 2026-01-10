#include <stdlib.h>
#include <stdbool.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    //с realloc можно было бы сделать лучше наверное, но ладно
    int* ans;
    bool c = 0;
    for (int i = digitsSize-1; i >= 0; i--) {
        if (digits[i] != 9) { break; }
        if (i == 0) { c = 1; }
    }
    if (c == 1) {
        ans = malloc(sizeof(int)*(digitsSize+1));
        *returnSize = digitsSize+1;
    } else {
        ans = malloc(sizeof(int)*digitsSize);
        *returnSize = digitsSize;
        c = 1;
    }

    for (int i = *returnSize-1; i >= 0; i--) {
        // printf("%d\n", i);
        if (*returnSize == digitsSize) {
            ans[i] = digits[i];
        } else {
            ans[i] = (i!=0) ? digits[i-1] : 0;
        }
        if (c) {
            ans[i]++;
            c = 0;
            if (ans[i] >= 10) {
                ans[i] = 0;
                c = 1;
            }
        }
    }

    return ans;
}
