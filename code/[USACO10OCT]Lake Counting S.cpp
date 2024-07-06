#include<bits/stdc++.h>
using namespace std;
int n,m,f,r,ans;
int dx[8] = {-1,0,1,1,1,0,-1,-1};
int dy[8] = {1,1,1,0,-1,-1,-1,0};
char ch;
bool Map[105][105];
struct node{
	int x,y;
}q[10005]; 
int main(){
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>ch;
			Map[i][j] = ch =='W';
		}
	for(int i = 1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(Map[i][j]){
				ans++;
				f = r = 1;
				q[f].x = i;
				q[f].y = j;
				Map[i][j] = false;
				while(f <=r){
					for(int k = 0;k<8;k++){
						int nx = q[f].x + dx[k];
						int ny = q[f].y + dy[k];
						if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&Map[nx][ny]){
							r++;
							q[r].x=nx;
							q[r].y=ny;
							Map[nx][ny] = false;
						}
					}
					f++;
				}
			} 
		}
	cout<<ans<<endl;
	return 0;
}
