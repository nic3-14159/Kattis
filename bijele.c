#include <stdio.h>

int main(){
	int expected[] = {1,1,2,2,2,8};
	int actual[6];
	for (int i = 0; i<6; i++){
		scanf("%d", &actual[i]);
		actual[i] = expected[i] - actual[i];
	}
	printf("%d %d %d %d %d %d\n", actual[0],actual[1],actual[2],actual[3],actual[4],actual[5]);
	return 0;
}
