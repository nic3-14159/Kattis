#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

int main(){
	int houses, cables;
	long long houseA, houseB;

	cin >> houses >> cables;
	unordered_set<long long> connections;
	vector<bool> hasInternet (houses, false);
	vector<bool> currLevel (houses, false);
	int currSize = 0;
	int nextSize = 0;
	vector<bool> nextLevel (houses, false);
	hasInternet[0] = true;

	while (cables > 0){
		cin >> houseA >> houseB;
		connections.insert((houseA-1)*200000 + (houseB-1));
		connections.insert((houseB-1)*200000 + (houseA-1));
		cables--;
	}
	currLevel[0] = true;
	currSize++;
	while(currSize != 0){
		for (int testNode = 0; testNode < houses; testNode++){
			if (currLevel[testNode]){
				for (int i = 0; i < houses; i++){
					if (!hasInternet[i] && connections.count(testNode*200000+i)){
						hasInternet[i] = true;
						nextLevel[i] = true;
						nextSize++;
					}
				}
			}
		}
		currLevel = nextLevel;
		currSize = nextSize;
		nextSize = 0;
		nextLevel = vector<bool> (houses, false);
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
