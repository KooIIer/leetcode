#include <stdlib.h>

int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int* ans;
    ans = malloc(numsSize*sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        // ans[i*2+((i-1)%2)] = nums[i];
        if (i >= n) {
            ans[1+(i-n)*2] = nums[i];
        } else {
            ans[i*2] = nums[i];
        }
    }
    *returnSize = numsSize;
    return ans;
}
