#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
	int houses, cables;
	int houseA, houseB;

	cin >> houses >> cables;
	vector<vector<bool>> connections (houses, vector<bool>(houses, false));
	vector<bool> hasInternet (houses, false);
	hasInternet[0] = true;
	queue<int> searchqueue;

	while (cables > 0){
		cin >> houseA >> houseB;
		connections[houseA-1][houseB-1] = true;
		connections[houseB-1][houseA-1] = true;
		cables--;
	}
	searchqueue.push(0);
	while(searchqueue.size() != 0){
		int nodes = searchqueue.size();
		while (nodes > 0){
			int testNode = searchqueue.front();
			for (int i = 0; i < houses; i++){
				if (i != testNode && connections[testNode][i] && !hasInternet[i]){
					hasInternet[i] = true;
					searchqueue.push(i);
				}
			}
			searchqueue.pop();
			nodes--;
		}
	}
	bool allConnected = true;
	for (int i = 0; i < houses; i++){
		if (!hasInternet[i]){
			allConnected = false;
			cout << i+1 << endl;
		}
	}
	if (allConnected)
		cout << "Conencted" << endl;
	return 0;
}
