#include <cstdio>
#include <string>
#include <list>
#include <map>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	char buf[n+1];
	string mirkoWord;
	string slavkoWord;
	scanf("%s", buf);
	string letterStr = string(buf);
	map<char, list<int>>letters;
	int lastPointer = letterStr.length()-1;
	
	for (int i = 0; i < n; i++){
		letters[buf[i]].push_back(i);
	}
	for (char i = 'a'; i <= 'z'; i++){
		letters[i].sort();
	}

	for (int i = 0; i < n; i++){
		if (i%2 == 0){ // Mirko's turn
			char c;
			while(letterStr[lastPointer] == '.'){
				lastPointer--;
			}
			c = letterStr[lastPointer];
			mirkoWord.push_back(c);
			letters[c].remove(lastPointer);
			letterStr[lastPointer] = '.';
		} else { // Slavko's turn
			for (char bestChar='a'; bestChar <= 'z'; ++bestChar){
				if (letters[bestChar].size() != 0){
					int pos = letters[bestChar].back();
					slavkoWord.push_back(bestChar);
					letterStr[pos] = '.';
					letters[bestChar].remove(letters[bestChar].back());
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
