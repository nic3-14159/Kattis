#include <iostream>
#include <string>
using namespace std;

int main(){
	string input, output="";
	cin >> input;
	for (char c : input){
		if (c == '<'){
			output.pop_back();
		} else {
			output.push_back(c);
		}
	}
	cout << output << endl;
	return 0;
}
