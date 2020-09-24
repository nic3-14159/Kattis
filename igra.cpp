#include <cstdio>
#include <string>

using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	char buf[n+1];
	string mirkoWord;
	string slavkoWord;
	scanf("%s", buf);
	string letters = string(buf);

	for (int i = 0; i < n; i++){
		if (i%2 == 0){ // Mirko's turn
			mirkoWord.push_back(letters.back());
			letters.pop_back();
		} else { // Slavko's turn
			string::iterator it = letters.begin();
			string::iterator bestChar = letters.begin();
			for (; it!=letters.end(); ++it){
				if (*it <= *bestChar){
					bestChar = it;
				}
			}
			slavkoWord.push_back(*bestChar);
			letters.erase(bestChar);
		}
	}
	if (slavkoWord.compare(mirkoWord) < 0){
		printf("DA\n");
	} else {
		printf("NE\n");
	}
	printf("%s\n", slavkoWord.c_str());
	return 0;
}
