#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cstdio>

using namespace std;

int main(){
	int houses, cables;
	int houseA, houseB;

	cin >> houses >> cables;
	vector<vector<int>> connections (houses, vector<int>());
	
	vector<bool> hasInternet (houses, false);
	unordered_set<int> currLevel;
	unordered_set<int> nextLevel;
	hasInternet[0] = true;

	while (cables > 0){
		scanf("%d %d", &houseA, &houseB);
		connections[houseA-1].push_back(houseB-1);
		connections[houseB-1].push_back(houseA-1);
		cables--;
	}
	currLevel.insert(0);
	while(!currLevel.empty()){
		for (int i : currLevel){
			for (int node : connections[i]){
				if (!hasInternet[node] && !nextLevel.count(node)){
					hasInternet[node] = true;
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
