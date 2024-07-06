#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,ans,t;
int dx[8]={2,1,-1,-2,-2,-1,1,2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};
bool a[15][15];
void dfs(int x1,int y1,int step){
	if(step==n*m){
		ans++;
	} else {
		for(int i=0;i<8;i++){
			int xx=x1+dx[i];
			int yy=y1+dy[i];
			if(xx<n&&yy<m&&xx>=0&&yy>=0&&a[xx][yy]!=true){
				a[xx][yy]=true;
				dfs(xx,yy,step+1);
				a[xx][yy]=false;
			} 
		}
		
	}
}
int main(){
	cin>>t;
	for(int k=1;k<=t;k++){
		ans=0;
		cin>>n>>m>>x>>y;
		a[x][y]=true;
		dfs(x,y,1);
 		a[x][y]=false;
		cout<<ans<<endl; 
 	}
	return 0;
}

