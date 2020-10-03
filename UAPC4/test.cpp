#include <iostream>

long long factorial(int n){
	return n == 0 ? 1 : n*factorial(n-1);
}

int main(){
	std::cout << factorial(40) << std::endl;
}
