#include <cstdio>
#include <cmath>

int main(){
	int m, n;
	bool lightCandle;
	float book_x, book_y, candle_x, candle_y;
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		scanf("%f %f %d", &book_x, &book_y, &n);
		lightCandle = false;
		for (int j = 0; j < n; j++){
			scanf("%f %f", &candle_x, &candle_y);
			if (sqrt(pow(candle_x-book_x, 2) + pow(candle_y-book_y, 2)) <= 8.0){
				lightCandle = true;
			}
		}
		if (lightCandle){
			printf("light a candle\n");
		} else {
			printf("curse the darkness\n");
		}
	}
	return 0;
}
