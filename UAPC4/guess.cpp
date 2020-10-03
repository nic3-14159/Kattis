#include <cstdio>
#include <string>
#include <iostream>

int main(){
	int guess = 500;
	int minGuess = 0, maxGuess = 1001;
	std::string response = "lower";
	while (response.compare("correct") != 0){
		std::cout << guess << std::endl;
		std::cin >> response;
		if (response.compare("lower") == 0){
			maxGuess = guess;
			guess = minGuess + (int)(guess-minGuess)/2;
		} else if (response.compare("higher") == 0){
			minGuess = guess;
			guess = guess + (int)((maxGuess - guess)/2);
		}
	}
	return 0;
}
