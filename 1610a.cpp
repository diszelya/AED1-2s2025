//implementação de grafos com matrizes

#include <stdio.h>

int main() {
	int t, n, m, a, b, i = 0, j, k, l;

	scanf("%d", &t);
	while (i < t) {
		scanf("%d", &n);
		scanf("%d", &m);
		
		int graph[n][n];
		
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				graph[j][k] = 0;
			}
		}
		
		l = 0;
		
		while (l < m){
		    scanf("%d", &a);
		    scanf("%d", &b);
		    graph[a-1][b-1]++;
		    l++;
		}
		
		i++;
	}

	return 0;
}
