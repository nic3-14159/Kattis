#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n = 0, m = 0;
	cin >> n;
	vector<int> nums(n, 0);
	for (int i = 0; i<n; i++){
		cin >> m;
		nums[i] = m;
	}
	for (int i = 1; i <= n; i++){
		cout << nums[n-i] << endl;
	}
	return 0;
}
