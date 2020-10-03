#include <stdio.h>
#include <algorithm>

int main(){
	int numHeads, numKnights, payment;
	do {
		payment = 0;
		scanf("%d %d", &numHeads, &numKnights);
		if (numHeads == 0 && numKnights == 0){
			break;
		}
		int heads[numHeads];
		int knights[numKnights];
		for (int i = 0; i < numHeads; ++i){
			scanf("%d", &heads[i]);
		}
		for (int i = 0; i < numKnights; ++i){
			scanf("%d", &knights[i]);
		}
		std::sort(heads, heads+numHeads);
		std::sort(knights, knights+numKnights);
		if (numKnights < numHeads){
			printf("Loowater is doomed!\n");
		} else {
			int knight_i = 0, head_i = 0;
			while (knight_i < numKnights && head_i < numHeads){
				if (knights[knight_i] >= heads[head_i]){
					payment += knights[knight_i];
					head_i++;
				}
				knight_i++;
			}
			if (head_i < numHeads) {
				printf("Loowater is doomed!\n");
			} else {
				printf("%d\n", payment);
			}
		}
	} while (numHeads != 0 && numKnights != 0);
	return 0;
}
