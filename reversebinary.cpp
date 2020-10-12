#include <iostream>
using namespace std;

int main(){
	unsigned int n, out = 0;
	cin >> n;
	while (n != 0){
		out = (out << 1) | (n & 1);
		n >>= 1;
	}
	cout << out << endl;
	return 0;
}
