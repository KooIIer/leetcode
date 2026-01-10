int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int m = 0;
    int c = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) { c = 0; continue; }
        c++;
        if (c > m) { m = c; }
    }
    return m;
}
