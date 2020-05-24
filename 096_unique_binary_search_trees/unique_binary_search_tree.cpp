#include <stdio.h>
#include <stdlib.h>

/* 递归写法 */
int numTreesResurve(int n){
    int sum = 0;
    if (n == 0){
        sum = 1;
    }
    for(int i = 0; i < n; ++i) {
        sum += numTreesResurve(i) * numTreesResurve(n - i - 1);
    }
    return sum;
}
/* 动态规划 */
int numTrees(int n) {
    int num[n + 1] = {0};
    num[0] = 1;
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 0; j < i; ++j) {
            num[i] += num[j] * num[i - j -1];    
        }
    }
    return num[n];
}
int main(){
    printf("%d\n", numTrees(10));
    return 0;
}