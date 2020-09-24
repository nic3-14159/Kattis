#include <stdio.h>

int main(){
	char charBuf[251];
	fgets(charBuf, sizeof(charBuf), stdin);
	for (int i = 0; charBuf[i] != 0; ++i){
		if (i == 0 ||  charBuf[i] != charBuf[i-1]){
			printf("%c",charBuf[i]);
		}
	}
	return 0;
}
