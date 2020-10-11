#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int numTests, length, numAnts, maxTime, minTime, antPos, distance;
	scanf("%d", &numTests);
	while (numTests > 0){
		scanf("%d %d", &length, &numAnts);
		maxTime = 0;
		minTime = 0;
		while (numAnts > 0){
			scanf("%d", &antPos);
			if (antPos < length && antPos > 0){
				distance = fmin(antPos, length-antPos);
				minTime = distance > minTime ? distance : minTime;
				distance = fmax(antPos, length-antPos);
				maxTime = distance > maxTime ? distance : maxTime;
			}
			numAnts--;
		}
		printf("%d %d\n", minTime, maxTime);
		numTests--;
	}
	return 0;
}
