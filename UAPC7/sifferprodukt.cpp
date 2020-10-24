#include <iostream>
using namespace std;

int main(){
	int x = 1;
	int temp = 1;
	cin >> x;
	while (x%10 != x){
		while (x != 0){
			if (x%10 != 0){
			       temp *= x%10;
			}
			x /= 10;
		}
		x = temp;
		temp = 1;
	}
	cout << x << endl;
	return 0;
}
