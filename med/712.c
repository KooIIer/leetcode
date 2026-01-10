#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*char* same(char* s1, char* s2) {
    // printf("%lu\n", strlen(s1));
   
    int ml = (int)fmin(strlen(s1), strlen(s2));
    // printf("%d\n", ml);

    for (int i = 0; i < ml; i++) {
        for (int j = i; j < ml; j++) {
            char p1[j-i+1];
            char p2[j-i+1];
            sprintf(p1, "%.*s", j-i+1, s1+i);
            sprintf(p2, "%.*s", j-i+1, s2+i);
            printf("%s; ", p1);
            printf("%s\n", p2);
            // if (strcmp() == 0 && )
        }
    }

    return "";
}*/

/*int f(char* s1, char* s2) {
    int tmp[122-97+1] = {0};
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    for (int i = 0; i < l1; i++) {
        tmp[(int)s1[i]-97]++;
    }
    for (int i = 0; i < l2; i++) {
        tmp[(int)s2[i]-97]--;
    }
    
    int r = 0;

    for (int i = 0; i < sizeof(tmp)/sizeof(int); i++) {
        if (tmp[i] == 0) { continue; }
        r += (97+i) * abs(tmp[i]);
        // printf("%c: %d\n", 97+i, tmp[i]);
    }
    return r;
}*/

/*int lcs(char* s1, char* s2, int a, int b) {
    if (a == 0 || b == 0) { return 0; }
    
    if (s1[a - 1] == s2[b - 1]) { return (int)s1[a-1] + lcs(s1, s2, a-1, b-1); }
    else { return fmax(lcs(s1, s2, a-1, b), lcs(s1, s2, a, b-1)); }
}*/

int lcs(char* s1, char* s2, int l1, int l2) {
    int dp[l1+1][l2+1];

    for (int i = 0; i <= l1; i++) {
        for (int j = 0; j <= l2; j++) {
            if (i == 0 || j == 0) { dp[i][j] = 0; }
            else if (s1[i-1] == s2[j-1]) { dp[i][j] = dp[i-1][j-1] + (int)s1[i-1]; }
            else {dp[i][j] = fmax(dp[i-1][j], dp[i][j-1]); }
        }    
    }
    return dp[l1][l2];
}

int as(char* s, int l) {
    int r = 0;
    for (int i = 0; i < l; i++) {
        r += (int)s[i];
    }
    return r;
}

int minimumDeleteSum(char* s1, char* s2) {
    // return lcs(s1, s2, strlen(s1), strlen(s2));
    // f(s1, s2);
    // return f(s1, s2);
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    return as(s1, l1) + as(s2, l2) - 2*lcs(s1, s2, l1, l2);
}

int main(int argc, char* argv[]) {
    if (argc < 3) { return 1; }
    printf("%d\n", minimumDeleteSum(argv[1], argv[2]));
    // printf("%d\n", minimumDeleteSum("delete", "leet"));

    return 0;
}
