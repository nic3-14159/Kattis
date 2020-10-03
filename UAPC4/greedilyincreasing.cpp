#include <stdio.h>
#include <iostream>
#include <string>

int main(){
	int n;
	scanf("%d", &n);
	int leftMost = 0;
	int currNum;
	std::string gis = "";
	int gisLen = 0;
	for (int i = 0; i < n; ++i){
		scanf("%d", &currNum);
		if (currNum > leftMost){
			leftMost = currNum;
			gis += " " + std::to_string(leftMost);
			gisLen++;
		}
		if (currNum == n){
			break;
		}
	}
	gis.erase(gis.begin());
	std::cout << gisLen << std::endl;
	std::cout << gis << std::endl;
	return 0;
}
