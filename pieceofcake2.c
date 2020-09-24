#include <stdio.h>

int main(){
	int sideLength, hCut, vCut;
	scanf("%d %d %d", &sideLength, &hCut, &vCut);
	int hMax = hCut > sideLength-hCut ? hCut : sideLength-hCut;
	int vMax = vCut > sideLength-vCut ? vCut : sideLength-vCut;
	printf("%d\n", hMax * vMax * 4);
	return 0;
}
