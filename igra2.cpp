#include <cstdio>
#include <string>
#include <cstdlib>

int main(){
	int n;
	scanf("%d", &n);
	
	//buffer for letter sequence
	char letterStr[n];
	//c strings for Mirko's and Slavko's words
	std::string mirkoWord = "";
	std::string slavkoWord = "";

	scanf("%s", letterStr);
	
	//each outer array is for one letter, inner array holds indices
	//of letter in letterSeq
	int **letters = new int* [26];
	for (int i = 0; i<26; i++){
		letters[i] = new int[n];
	}

	//index of rightmost letter in letterSeq
	int lastLetterIdx = n-1;
	//index of last character index in letters
	int letterP[26];
	int tmp;

	for (int i = 0; i<26; i++){
		letterP[i] = -1;
	}

	for (int i = 0; i < n; i++){
		tmp = letterStr[i]-'a';
		//printf("%d %d\n", tmp, i);
		letterP[tmp]++;
		letters[tmp][letterP[tmp]] = i;
	}

	for (int i = 0; i < n; i++){
		if (i%2 == 0){ // Mirko's turn
			char c;
			while(letterStr[lastLetterIdx] == '.'){
				lastLetterIdx--;
			}
			c = letterStr[lastLetterIdx];
			mirkoWord.push_back(c);
			letterP[c-97]--;
			letterStr[lastLetterIdx] = '.';
		} else { // Slavko's turn
			for (char bestChar='a'; bestChar <= 'z'; ++bestChar){
				tmp = bestChar - 'a';
				if (letterP[tmp] > -1){
					int pos = letters[tmp][letterP[tmp]];
					slavkoWord.push_back(bestChar);
					letterStr[pos] = '.';
					letterP[tmp]--;
					break;
				}
			}
		}
		//printf("%s %s %s\n", slavkoWord.c_str(),mirkoWord.c_str(),letterStr);
	}
	if (slavkoWord.compare(mirkoWord) < 0){
		printf("DA\n");
	} else {
		printf("NE\n");
	}
	printf("%s\n", slavkoWord.c_str());
	for (int i = 0; i<26; i++){
		free(letters[i]);
	}
	free(letters);
	return 0;
}
