#include<bits/stdc++.h>
using namespace std;
int n,b,a[45][45],dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char a1;
bool flag;
int dfs(int x,int y,int step){
	if(x==n&&y==n){
	for(int k=2;k<=n*n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){ 
				if(a[i][j]==k){
					if(i==n&&j==n){
						cout<<'('<<i<<','<<j<<')';
					} else {
						cout<<'('<<i<<','<<j<<')'<<"->";
						flag=true;
						break;
					}
				}
			}
			if(flag==true){
				flag=false;
				break;
			} 
		}
	} 
	return 0;
	} else {
		for(int i=0;i<4;i++){
			int tx=x+dx[i],ty=y+dy[i];
			if(tx>=1&&ty>=1&&tx<=n&&ty<=n&&a[tx][ty]==0){
				a[tx][ty]=step+2;
				dfs(tx,ty,step+1);
				a[tx][ty]=0;
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a1; 
			a[i][j]=int(a1)-48; 
		}
	}
	a[1][1]=2;
	dfs(1,1,1);
	return 0;
}
