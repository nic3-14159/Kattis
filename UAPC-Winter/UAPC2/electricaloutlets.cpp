#include <iostream>
using namespace std;

int main(){
	int n, k, outlet, count;
	cin >> n;
	while (n--){
		cin >> k;
		count = 0;
		for (int i = 0; i<k; i++){
			cin >> outlet;
			count += outlet;
		}
		cout << count - k+1 << endl;
	}
	return 0;
}
