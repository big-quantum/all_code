#include<bits/stdc++.h>
using namespace std;
int n,m,mapp[105][105],maxx,land;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char num;
struct node{
	int x,y;
}que[10005];
int bfs(int i,int j){
	int front=0,last=1;
	que[front].x=i;
	que[front].y=j;
	int space=1;
	while(front<last){
		for(int i=0;i<4;i++){
			int xx=que[front].x+dx[i],yy=que[front].y+dy[i];
			if(xx>0&&xx<=n&&yy>0&&yy<=m&&mapp[xx][yy]!=0){
				que[last].x=xx;
				que[last].y=yy;
				space++;
				mapp[xx][yy]=0;
				last++;
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
			cin>>num;
			mapp[i][j]=num-'0'; 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mapp[i][j]!=0){
				mapp[i][j]=0;
				land++;
				maxx=max(maxx,bfs(i,j));
			}
		}
	}
	cout<<land<<" "<<maxx<<endl;
	return 0;
}
/*4 10
0234500067
1034560500
2045600671
0000000089*/
