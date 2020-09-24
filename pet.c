#include <stdio.h>

int main(){
	int score1,score2,score3,score4;
	int winnerNum = 0;
	int winnerScore = 0;
	for (int i = 0; i < 5; ++i){
		scanf("%d %d %d %d", &score1, &score2, &score3, &score4);
		int total = score1 + score2 + score3 + score4; 
		if (total > winnerScore){
			winnerNum = i+1;
			winnerScore = total;
		}
	}
	printf("%d %d\n", winnerNum, winnerScore);
	return 0;
}
