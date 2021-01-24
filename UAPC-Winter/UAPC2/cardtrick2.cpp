#include <iostream>
#include <deque>
using namespace std;

int main(){
	int n, cards;
	cin >> n;
	deque<int> deck;
	while (n--){
		cin >> cards;
		while (cards--){
			deck.push_front(cards);
			for (int i=0; i<=cards; i++){
				deck.push_front(deck.back());
				deck.pop_back();
			}
		}
		for (auto it=deck.begin(); it<deck.end(); it++)
			cout << (*it)+1 << (it==deck.end()-1 ? "" : " ");
		cout << endl;
		deck.clear();
	}
	return 0;
}
