#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char word[17];
	char alphabet[27];
	cin >> word >> alphabet;
	int hangman = 0;
	bool wrong = true;
	int count = 0;
	for (int c = 0; c<26 && count < strlen(word); c++){
		for (char *i = word; *i != 0; i++){
			if (*i == alphabet[c]){
				wrong = false;
				count++;
			}
		}
		if (wrong){
			hangman++;
		}
		wrong = true;
	}
	if (hangman < 10){
		cout << "WIN" << endl;
	} else {
		cout << "LOSE" << endl;
	}
	return 0;
}
