#include <stdlib.h>

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int* ans;
    ans = malloc(2*sizeof(int));
    *returnSize = 2;
    int xor = 0;
    for (int i = 1; i < numsSize+1; i++) {
        xor ^= i;
    }
    for (int i = 0; i < numsSize; i++) {
        xor ^= nums[i];
    }
    int x1 = 0;
    int x2 = 0;

    int m = 1;
    while ((xor & m) == 0) { m = m << 1; }

    for (int i = 0; i < numsSize; i++) {
        // printf("%d\n", nums[i]%2);
        if (nums[i] & m) {
            x1 ^= nums[i];
            // printf("%d\n", nums[i]);
        } else {
            x2 ^= nums[i];
        }
    }
    for (int i = 1; i < numsSize+1; i++) {
        if (i & m) {
            x1 ^= i;
        } else {
            x2 ^= i;
        }
    }

    int c = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == x1) { c++; }
    }
    if (c == 2) { ans[0] = x1; ans[1] = x2; }
    else { ans[0] = x2; ans[1] = x1; }

    return ans;
}
