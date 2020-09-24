#include <stdio.h>
#include <string.h>

int main(){
	char buf[5001];
	setvbuf(stdin, buf, _IOFBF, sizeof(buf));
	scanf("%s", buf);
	printf("%s\n", buf);
	return 0;
}
