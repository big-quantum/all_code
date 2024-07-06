#include<bits/stdc++.h>
using namespace std;
int w,h,sx,sy,mapp[25][25],ans;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
struct node{
	int x,y;
}a; 
queue<node>que;
int main(){
	cin>>h>>w;
	for(int i=1;i<=w;i++){
		for(int j=1;j<=h;j++){
			char num;
			cin>>num;
			if(num=='#') mapp[i][j]=1;
			if(num=='@'){
				a.x=i;
				a.y=j;
				que.push(a);
				ans=1;
				mapp[i][j]=1;
			}
		}
	}
	while(!que.empty()){
		for(int i=0;i<4;i++){
			int xx=que.front().x+dx[i],yy=que.front().y+dy[i];
			if(xx>0&&xx<=w&&yy>0&&yy<=h&&mapp[xx][yy]==0){
				node tmp;
				tmp.x=xx;
				tmp.y=yy;
				ans++;
				mapp[xx][yy]=1;
				que.push(tmp); 
			}
		}
		que.pop();
	}
	cout<<ans<<endl;
	return 0;
} 
//https://oj.czos.cn/p/1897
