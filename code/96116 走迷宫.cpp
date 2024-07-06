#include<bits/stdc++.h>
using namespace std;
int n,b,dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
char a[45][45];
bool flag;
struct node{
	int x,y;
}que[30000];
void dfs(int x,int y,int step){
	que[step].x=x;
	que[step].y=y;
	a[x][y]='1';
	if(x==n&&y==n){
		cout<<"(1,1)";
		for(int k=2;k<=step;k++)
			cout<<"->"<<'('<<que[k].x<<','<<que[k].y<<')';
		return;
		} else {
		for(int i=0;i<4;i++){
			int tx=x+dx[i],ty=y+dy[i];
			if(tx>=1&&ty>=1&&tx<=n&&ty<=n&&a[tx][ty]=='0'){
				dfs(tx,ty,step+1);
			}
		}
	}
	//a[x][y]='0';
	return;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j]; 
		}
	}
	dfs(1,1,1);
	return 0;
}

