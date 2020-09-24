#include <stdio.h>

int modMath(n, x, y, op){
	int result = 0;
	switch (op){
	case '+':
		result = (x + y) % n;
		break;
	case '-':
		result = (n - y + x) % n;
		break;
	case '*':
		result = (x * y) % n;
		break;
	case '/':
		if ((y % n) == 0){
			result = -1;
		} else {
			result = 
		}
	}
	return result;
}

int main(){
	int n = -1, t = -1;
	int x, y;
	char operation;
	while(n != 0 && t != 0){
		scanf("%d %d", &n, &t);
		for (int i = 0; i < t; i++){
			scanf("%d %c %d", &x, &operation, &y);
			printf("%d\n", modMath(n, x, y, operation));
		}
	}
	return 0;
}
