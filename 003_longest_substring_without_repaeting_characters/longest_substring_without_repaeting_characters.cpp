
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX(a, b) ((a) < (b) ? (b) :(a))

int lengthOfLongestSubstring(char * s){
    int len = 0;
    int index[256];
    int start = 0, end = 0;
    memset(index, -1, sizeof(index));
    for (; s[end] != '\0'; ++end) {
        printf("%d-%d-%d\n", start, end, index[s[end]]);
        if (start <= index[s[end]]) {
            len = MAX(len, end - start);
            start = index[s[end]] + 1;
        }
        index[s[end]] = end;        
    }
    return MAX(len, end - start);
}


int main(){
    printf("%d\n", lengthOfLongestSubstring("pwwkew"));
    return 0;
}