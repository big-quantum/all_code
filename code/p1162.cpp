#include<bits/stdc++.h>
using namespace std;
int n,f,r,Map[35][35],vis[35][35];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

struct node{
	int x,y;
}q[905]; 

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			cin >> Map[i][j];
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			if ((i == 1 || i == n || j == 1 || j == n) && !vis[i][j] && Map[i][j] == 0){
				f = r = 1;
				q[f].x = i;
				q[f].y = j;
				vis[i][j] = true;
				while(f <= r){
					for(int k = 0;k < 4;k++){
						int nx = q[f].x + dx[k];
						int ny = q[f].y + dy[k];
						if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !vis[nx][ny] && Map[nx][ny] == 0){
							r++;
							q[r].x = nx;
							q[r].y = ny;
							vis[nx][ny] = true;
						}
					}
					f++;
				}
			}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			if (!vis[i][j] && Map[i][j] == 0){
				f = 1;
				r = 1;
				q[f].x = i;
				q[f].y = j;
				vis[i][j] = true;
				Map[i][j] = 2;
				while(f <= r){
					for(int k = 0;k < 4;k++){
						int nx = q[f].x + dx[k];
						int ny = q[f].y + dy[k];
						if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && Map[nx][ny] == 0 && !vis[nx][ny]){
							r++;
							q[r].x = nx;
							q[r].y = ny;
							vis[nx][ny] = true;
							Map[nx][ny] = 2;
						}
					}
					f++;
				}		
				
			}				
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < n;j++)
			cout << Map[i][j] << " ";
		cout << Map[i][n] << endl;
	}
	return 0;
}
