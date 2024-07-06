#include<bits/stdc++.h>
using namespace std;
#define Maxn 405
int s[Maxn][Maxn];
bool vis[Maxn][Maxn];
struct node{
	int x,y;
}q[160005];
int dx[8] = {-2,-1,1,2, 2, 1,-1,-2};
int dy[8] = { 1, 2,2,1,-1,-2,-2,-1};
int n,m,sx,sy,f,r;
int main(){
	cin >> n >> m >> sx >> sy;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			s[i][j] = -1;
	f = 1;
	r = 1;
	q[f].x = sx;
	q[f].y = sy;
	s[sx][sy] = 0;
	vis[sx][sy] = true;
	while(f <= r){
		for(int k = 0;k < 8;k++){
			int nx = q[f].x + dx[k];
			int ny = q[f].y + dy[k];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny]){
				r++;
				q[r].x = nx;
				q[r].y = ny;
				vis[nx][ny] = true;
				s[nx][ny] = s[q[f].x][q[f].y] + 1;
			}
		}
		f++;	
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++)
			printf("%-5d",s[i][j]);
		printf("\n");		
	}
	return 0;
}
