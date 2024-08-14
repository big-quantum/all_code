#include<bits/stdc++.h>
using namespace std;

int n, m, st[100005][30], lg[100005];

void init(){
	for(int i = 2; i <= n; i++){
		lg[i] = lg[i / 2] + 1;
	}
	for(int i = 1; i <= lg[n]; i++){
		for(int j = 1; j <= n - (1 << i) + 1; j++){
			st[j][i] = max(st[j][i - 1], st[j +(1 << (i - 1))][i - 1]);
		}
	}
}


int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &st[i][0]);
	}
	init();
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		int se = lg[y - x + 1];
		printf("%d\n", max(st[x][se], st[y - (1 << se) + 1][se]));
	}
	return 0;
}
