#include <stdlib.h>
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int* ans;
    ans = malloc(numsSize*2*sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        ans[i] = nums[i];
        ans[i+numsSize] = nums[i];
    }
    *returnSize = numsSize*2;
    return ans;
}

int main() {
    int nums[] = {1,2,1};
    int returnSize;
    int* ans = getConcatenation(nums, 3, &returnSize);
    free(ans);
    return 0;
}
