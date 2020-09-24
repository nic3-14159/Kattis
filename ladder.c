#include <stdio.h>
#include <math.h>

int main(){
	double pi = acos(-1);
	int height, angle;
	scanf("%d %d", &height, &angle);
	printf("%d\n", (int)ceil((double)height / sin((double)angle/180.0*pi)));
	return 0;
}
