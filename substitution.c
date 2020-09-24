#include <stdio.h>
#include <string.h>

int main(){
	int numCases = 0;
	int subTable[100];
	scanf("%d", &numCases);
	for (int testCase = 0; testCase < numCases; ++testCase){
		int messageChar1, cryptoChar1;
		int k = 0;
		scanf("%*d\n%d %*s\n%d %*s\n", &messageChar1, &cryptoChar1);
		for (int letter = 0; letter < 100; ++letter){
			scanf("%d", &subTable[letter]);
		}
		while (subTable[messageChar1 - 1] != cryptoChar1){
			messageChar1 = subTable[messageChar1 - 1];
			k++;
		}
		printf("%d\n", k);
	}
	return 0;
}
