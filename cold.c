#include <stdio.h>

int main(){
	int n, temp;
	int negTempCount = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d", &temp);
		negTempCount += (temp < 0);
	}
	printf("%d\n", negTempCount);
	return 0;
}
