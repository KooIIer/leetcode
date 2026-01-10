#include <stdio.h>
// #include <string.h>

// typedef struct {
    // int num;
    // int i;
// } map;

int repeatedNTimes(int* nums, int numsSize) {
    // map m[numsSize/2+1];
    // memset(m, 0, sizeof(m));
    // for (int i = 0; i < numsSize; i++) {
        // if (m) { return nums[i]; }
    // }
    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < numsSize-i; j++) {
            if (nums[j] == nums[j+i]) { return nums[j]; }
        }
    }
    return 0;
}

int main() {
    int nums[] = {2,1,2,5,3,2};
    // int nums[] = {1,2,3,3};
    // int nums[] = {2,6,2,1};
    printf("%d\n", repeatedNTimes(nums, sizeof(nums)/sizeof(int)));
    return 0;
}
