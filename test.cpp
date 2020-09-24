#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	char buf[100001];
	scanf("%s", buf);
	string letters = string(buf);
	letters.rfind('a');
	return 0;
}
