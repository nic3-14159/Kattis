#include <stdio.h>

int main(){
	long long a, b, diff;
	while (scanf("%llu %llu", &a, &b) != EOF){
		diff = a-b;
		printf("%llu\n", diff < 0 ? -diff : diff);
	}
	return 0;
}
