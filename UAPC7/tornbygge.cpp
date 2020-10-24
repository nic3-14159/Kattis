#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n, num;
	int count = 1;
	int last = 1000001;
	cin >> n;
	while (n != 0){
		cin >> num;
		if (num > last){
			count++;
		}
		last = num;
		n--;
	}
	cout << count << endl;
	return 0;
}
