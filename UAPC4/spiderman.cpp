#include <stdio.h>
#include <iostream>
#include <stack>
bool test(int *distances, char *directions, int length, int n, int sum){
	printf("%d %d\n", n, sum);
	if (n == length){
		if (sum == 0){
			return true;
		} else {
			return false;
		}
	}
	if (sum < 0){
		return false;
	}
	//check if climbing down leads to an answer
	if (test(distances, directions, length, n+1, sum-distances[n])){
		directions[n] = 'D';
		return true;
	} else {
		//climbing down did not lead to an answer, so climb up
		directions[n] = 'U';
		return test(distances, directions, length, n+1, sum+distances[n]);
	}
}

bool testRunLength(int *distances, char *directions, int start, int length, int end){
	while (end < length){
		if (start == length){
			return true;
		}
		if (test(distances, directions, end, start + 1, distances[start])){
			if (testRunLength(distances, directions, end, length, end)){
				return true;
			} else {
				end++;
			}
		} else {
			end++;
		}
	}
	return false;
}
/*
bool testRunLength(int *distances, char *directions, int length){
	std::stack<int> runLengths;
	runLengths.push(1);
	int pos = 0;
	while (true){
		if (runLengths.size() == 0){
			return true;
		}
		if (test(distances, directions, runLengths.top(), pos+1, distances[pos])){
			pos = runLengths.top();
			runLengths.push(runLengths.top()+1);
		} else {
			if (runLengths.top() == length){
				if (pos == length){
					return false;
				} else {
					runLengths.pop();
				}
			}
			runLengths.top()++;
		}
	}
}*/

int main(){
	int tests, m;
	std::cin >> tests;
	for (int i=0; i<tests; i++){
		std::cin >> m;
		int distances[m];
		for (int j = 0; j<m; j++){
			scanf("%d", &distances[j]);
		}
		char directions[m+1];
		directions[m] = 0;
		directions[0] = 'U';
		std::cout << test(distances, directions, 3, 2, distances[1]) << std::endl;
		std::cout << test(distances, directions, 4, 2, distances[1]) << std::endl;
		if (testRunLength(distances, directions, 0, m, 1)){
			std::cout << directions << std::endl;
		} else {
			std::cout << "IMPOSSIBLE" << std::endl;
		}
	}
	return 0;
}
