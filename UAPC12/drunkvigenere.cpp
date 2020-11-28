#include <bits/stdc++.h>
using namespace std;

int main(){
	string message, key;
	cin >> message >> key;
	for (int i = 0; i < message.length(); i++){
		int shift = (key[i]-'A')*(i&1 ? 1 : -1);
		int letter = message[i]-'A'+shift;
		cout << (char)(max(letter%26, (letter+26) % 26)+'A');
	}
	cout << endl;
	return 0;
}
