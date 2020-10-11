#include <cstdio>

int main(){
	int n = 0;
	scanf("%d", &n);
	int temp;
	while (n != -1){
		bool graph[n][n];
		bool vertices[n];
		for (int i=0; i<n; i++){
			vertices[i] = false;
			for (int j=0; j<n; j++){
				scanf("%d", &temp);
				graph[i][j] = (bool)temp;
			}
		}
		for (int i = 0; i < n-2; i++){
			for (int j = i+1; j < n-1; j++){
				for (int k = j+1; k < n; k++){
					bool partTriangle = graph[i][j] && graph[i][k] && graph[j][k];
					vertices[i] |= partTriangle;
					vertices[j] |= partTriangle;
					vertices[k] |= partTriangle;
				}
			}
		}
		for (int i = 0; i < n; i++){
			if (!vertices[i]){
				printf("%d ", i);
			}
		}
		printf("\n");
		scanf("%d", &n);
	}
	return 0;
}
