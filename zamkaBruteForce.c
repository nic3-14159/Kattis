#include <stdio.h>
#include <math.h>

int main(){
	/* L is the lower bound of search
	 * D is the upper bound of search
	 * X is the target value
	 * N is the minimum integer who's digits sum to X
	 * M is the maximum integer who's digits sum to X
	 * numDigits is the number of place values of D
	 */
	int L, D, X, N, M, numDigits;
	scanf("%d\n%d\n%d\n",&L, &D, &X);
	numDigits = (int)log10(D);
	for (int i = 0; i < numDigits; ++i){
		int digit = fmax(9,X);
		N += digit * (int)pow(10, i);
		M += digit * (int)pow(10, numDigits-i)
	}
}
