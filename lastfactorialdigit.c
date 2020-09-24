#include <stdio.h>

int main(){
    int t, n;
    scanf("%d", &t);
    for (int testCase = 0; testCase < t; ++testCase){
        int lastDigit = 1;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i){
            lastDigit = (lastDigit * i) % 10;
        }
        printf("%d\n", lastDigit);
    }
}
