#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	// raw map given, with sea border
	vector<vector<bool>> islandMap (n+2, vector<bool>(m+2, false));
	// map of all squares that are sea
	vector<vector<bool>> seaMap (n+2, vector<bool>(m+2, false));
	vector<bool> inSearch ((m+2)*(n+2), false);
	vector<int> currSearch;
	vector<int> nextSearch;
	currSearch.resize((n+2)*(m+2));
	nextSearch.resize((n+2)*(m+2));
	char buffer[1001] = "";
	int coastLen = 0;
	for (int row = 0; row < n+2; row++){
		bool firstLastRow = (row == 0 || row == n+1);
		// only read row data if not on sea border
		if (!firstLastRow){
			cin >> buffer;
		}
		for (int col = 0; col < m+2; col++){
			// add sea border to root of breadth first search, set
			// to true in seaMap
			if (firstLastRow || col == 0 || col == m+1){
				currSearch.push_back(row * (m+2) + col);
				seaMap[row][col] = true;
			} else {
				islandMap[row][col] = buffer[col-1] == '1' ? true : false;
			}
		}
	}
	// check each block up, down, left, right if is water
	while (currSearch.size() != 0){
		for (int i : currSearch){
			int row = i/(m+2);
			int col = i%(m+2);
			bool upIsSea = (row != 0 && !islandMap[row-1][col]);
			bool downIsSea = (row != n+1 && !islandMap[row+1][col]);
			bool leftIsSea = (col != 0 && !islandMap[row][col-1]);
			bool rightIsSea = (col != m+1 && !islandMap[row][col+1]);

			if (row != 0 && islandMap[row-1][col])
				coastLen++;
			if (row != n+1 && islandMap[row+1][col])
				coastLen++;
			if (col != 0 && islandMap[row][col-1])
				coastLen++;
			if (col != m+1 && islandMap[row][col+1])
				coastLen++;
			//up
			if (upIsSea && !seaMap[row-1][col] && !inSearch[(row-1)*(m+2)+col]){
				nextSearch.push_back((row-1)*(m+2)+col);
				inSearch[(row-1)*(m+2)+col] = true;
				seaMap[row-1][col] = true;
			}
			//down
			if (downIsSea && !seaMap[row+1][col] && !inSearch[(row+1)*(m+2)+col]){
				nextSearch.push_back((row+1)*(m+2)+col);
				inSearch[(row+1)*(m+2)+col] = true;
				seaMap[row+1][col] = true;
			}
			//left
			if (leftIsSea && !seaMap[row][col-1] && !inSearch[row*(m+2)+(col-1)]){
				nextSearch.push_back((row)*(m+2)+(col-1));
				inSearch[row*(m+2)+(col-1)] = true;
				seaMap[row][col-1] = true;
			}
			//right
			if (rightIsSea && !seaMap[row][col+1] && !inSearch[row*(m+1)+(col+1)]){
				nextSearch.push_back((row)*(m+2)+(col+1));
				inSearch[row*(m+2)+(col+1)] = true;
				seaMap[row][col+1] = true;
			}
		}
		currSearch = nextSearch;
		nextSearch.clear();
		inSearch = vector<bool>((n+2)*(m+2), false);
	}
	
	// print map
	for (int row = 0; row < n+2; row++){
		for (int col = 0; col < m+2; col++){
			cout << seaMap[row][col];
		}
		cout << endl;
	}
	cout << coastLen << endl;
	return 0;
}
