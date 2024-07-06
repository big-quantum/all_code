#include<bits/stdc++.h>
using namespace std;
srting s1,s2;
bool vis[9][9][9][9][9][9][9][9][9];
int d[9][4]={{1,3},{-1,1,4},{-1,5},{0,4,6},{1,5,7,3},{2,4,8},{3,7},{6,4,8},{5,7}};
//int mapp[5][5],dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},q[5][5][50005];
int front=0,rear=1;
struct node{
	string s;
	int step,x,y;
}q[50005];
void flag(string s){
	vis[s[0]-'0'][s[1]-'0'][s[2]-'0'][s[3]-'0'][s[4]-'0'][s[5]-'0'][s[6]-'0'][s[7]-'0'][s[8]-'0']=true;
}
int main(){
	cin>>s1>>s2;
	int len=s1.size(),cnt=0;
	/*for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			mapp[i][j]=s[cnt]-'0';
			cnt++; 
			q[i][j][front]=mapp[i][j];
		}
	} */
	flag(s1);
	q[front].s=s1;
	q[front].step=0;
	q[front].x=2;
	q[front].y=2;
	while(front<rear){
		for(int i=1;i<=n;i++)
	}
	return 0;
}
