#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n, m, a, c, x0;
	int count = 0;
	cin >> n >> m >> a >> c >> x0;
	vector<long long> seq(n, 0);
	set<long long> unique;
	for (int i = 0; i < n; i++){
		if (i == 0){
			seq[0] = (a*x0 + c) % m;
		} else {
			seq[i] = (a*seq[i-1] + c) % m;
		}
		unique.insert(seq[i]);
	}
	for (auto i : unique){
		int low = 0;
		int high = seq.size()-1;
		int mid;
		while (low <= high) {
			mid = (low+high)/2;
			if (seq[mid] == i){
				count++;
				break;
			}
			if (i < seq[mid]){
				high = mid-1;
			} else {
				low = mid+1;
			}
		}

	}
	cout << count << endl;
	return 0;
}
