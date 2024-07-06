#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,f,r,Map[1005][1005],g[1005][1005],t,cnt[1000005];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
bool vis[1005][1005];
struct node{
	int x,y;
}q[1000005];
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> s;
		for(int j = 1;j <= n;j++)
			Map[i][j] = s[j - 1] - '0';
	}
	while(m--){
		int i,j;
		cin >> i >> j;
		if (!vis[i][j]){
			t++;
			f = r = 1;
			vis[i][j] = true;
			q[f].x = i;
			q[f].y = j;
			g[i][j] = t;
			while(f <= r){
				for(int k = 0;k < 4;k++){
					int nx = q[f].x + dx[k];
					int ny = q[f].y + dy[k];
					if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !vis[nx][ny] && Map[nx][ny] != Map[q[f].x][q[f].y]){
						r++;
						q[r].x = nx;
						q[r].y = ny;
						g[nx][ny] = t;
						vis[nx][ny] = true;
					}
				}
				f++;	
			}
			cnt[t] = r;
			cout << r << endl;			
		} 
		else
			cout << cnt[g[i][j]] << endl;	
	}
	return 0;
} 
