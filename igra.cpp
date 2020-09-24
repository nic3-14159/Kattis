#include <cstdio>
#include <string>
#include <deque>
#include <map>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	char letterStr[n+1];
	string mirkoWord;
	string slavkoWord;
	scanf("%s", letterStr);
	map<char, deque<int>>letters;
	int lastPointer = n-1;
	
	for (int i = 0; i < n; i++){
		letters[letterStr[i]].push_back(i);
	}

	for (int i = 0; i < n; i++){
		if (i%2 == 0){ // Mirko's turn
			char c;
			while(letterStr[lastPointer] == '.'){
				lastPointer--;
			}
			c = letterStr[lastPointer];
			mirkoWord.push_back(c);
			letters[c].pop_back();
			letterStr[lastPointer] = '.';
		} else { // Slavko's turn
			for (char bestChar='a'; bestChar <= 'z'; ++bestChar){
				if (letters[bestChar].size() != 0){
					int pos = letters[bestChar].back();
					slavkoWord.push_back(bestChar);
					letterStr[pos] = '.';
					letters[bestChar].pop_back();
					break;
				}
			}
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
