#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <cstdio>

using namespace std;

int main(){
	int houses, cables;
	int houseA, houseB;

	cin >> houses >> cables;
	map<int, unordered_set<int>> connections;
	
	vector<bool> hasInternet (houses, false);
	unordered_set<int> currLevel;
	unordered_set<int> nextLevel;
	hasInternet[0] = true;

	while (cables > 0){
		cin >> houseA >> houseB;
		connections[houseA].insert(houseB);
		connections[houseB].insert(houseA);
		cables--;
	}
	currLevel.insert(1);
	while(!currLevel.empty()){
		for (int i : currLevel){
			for (int node : connections[i]){
				if (!hasInternet[node-1] && !nextLevel.count(node)){
					hasInternet[node-1] = true;
					nextLevel.insert(node);
				}
			}
		}
		currLevel = nextLevel;
		nextLevel.clear();
	}
	bool allConnected = true;
	for (int i = 0; i < houses; i++){
		if (!hasInternet[i]){
			allConnected = false;
			cout << i+1 << endl;
		}
	}
	if (allConnected)
		cout << "Connected" << endl;
	return 0;
}
