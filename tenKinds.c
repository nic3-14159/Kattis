#include <stdio.h>
#include <stdlib.h>

int main(){
	int rows, cols;
	scanf("%d %d", &rows, &cols);
	char zoneMap[rows][cols];
	for (int row = 0; row < rows; ++row){
		scanf("%s",zoneMap[row]);
	}
	int numQueries;
	scanf("%d", &numQueries);
	int r1, c1, r2, c2;
	for (int i=0; i < numQueries; ++i){
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		char sourceChar = zoneMap[r1-1][c1-1];
		char destChar = zoneMap[r2-1][c2-1];
		char *output;
		switch(sourceChar){
			case '0':
				output = "binary";
				break;
			case '1':
				output = "decimal";
				break;
		}
		if (sourceChar == destChar){
			printf("%s\n", output);
		} else {
			printf("neither\n");
		}
	}
	return 0;
}
