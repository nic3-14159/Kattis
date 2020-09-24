#include <stdio.h>

int main(){
	int nums[100000];
	for (int i = 0; i < 100000; ++i){
		nums[i] = i;
	}
	int sum = 0;
	for (int i = 0; i < 100000; ++i){
		sum += nums[i];
	}
	printf("%d\n", sum);
	return 0;
}
