#include <stdio.h>

int main(){
	int a = 0, b = 0, h = 0;
	int currHeight = 0;
	int count = 0;
	scanf("%d %d %d", &a, &b, &h);
	while (currHeight < h){
		currHeight += a;
		count++;
		if (currHeight >= h)
			break;
		currHeight -= b;
	}
	printf("%d\n", count);
}
