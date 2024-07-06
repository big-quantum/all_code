#include<bits/stdc++.h>//dfs算法 
using namespace std;
int n,m,ans=INT_MAX,mapp[35][35];
int dx[4]={0,1},dy[4]={1,0};//不对 不能只向下或向右走 
//不知道如何打标记 flag[35][35]; 
struct node{
	int x,y,num;
};
queue<node> que; 
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mapp[i][j];
		}
	}
	node tmp;
	tmp.x=1;
	tmp.y=1;
	tmp.num=mapp[1][1];
	que.push(tmp);
	while(!que.empty()){
		if(que.front().x==n&&que.front().y==m){
			ans=min(ans,que.front().num);
			que.pop();
			continue;
		}
		for(int i=0;i<2;i++){
			int xx=que.front().x+dx[i],yy=que.front().y+dy[i];
			if(xx>0&&xx<=n&&yy>0&&yy<=m){
				node a;
				a.x=xx;
				a.y=yy;
				a.num=que.front().num+mapp[xx][yy];
				que.push(a);
			} 
		}
		que.pop();
	}
	cout<<ans<<endl;
	return 0;
}
//https://oj.czos.cn/p/1541
