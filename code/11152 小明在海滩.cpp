#include<bits/stdc++.h>
using namespace std;
int n,m,mapp[1005][1005],ans,maxans;
char a1;
int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={1,1,0,-1,-1,-1,0,1};
struct node{
	int x,y;
}que[10005];
int bfs(int i,int j){
	int front=0,rear=1;
	que[front].x=i;
	que[front].y=j;
	int space=1;
	while(front<rear){
		for(int i=0;i<8;i++){
			int xx=que[front].x+dx[i];
			int yy=que[front].y+dy[i];
			if(xx>0&&yy>0&&xx<=n&&yy<=m&&mapp[xx][yy]){
				que[rear].x=xx;
				que[rear].y=yy;
				space++;
				mapp[xx][yy]=0;
				rear++;
			}
		}
		front++;
	}
	return space;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a1;
			if(a1=='.')	mapp[i][j]=0;
			else{
				for(int k=0;k<8;k++){
					
				} 
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mapp[i][j]){
				mapp[i][j]=0;
				ans=bfs(i,j);
				maxans=max(maxans,ans);
			}
		}
	}
	cout<<maxans<<endl;
	return 0; 
}
