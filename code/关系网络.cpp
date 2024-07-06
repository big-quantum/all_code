#include<bits/stdc++.h>
using namespace std;
int a[105][105],q[10010][2],x,y,n;
bool p[105];
void bfs(){
	int f=1;
	int l=1; 
	int now;
	q[f][0]=x;
	q[f][1]=0;
	p[x]=true;
	while(f<=l){
		now=q[f][0];
		if(now==y){
			cout<<q[f][1]-1<<endl;
			return;
		}
		for(int i=1;i<=n;i++){
			if(!p[i]&&a[i][now]){
				l++;
				q[l][0]=i;
				q[l][1]=q[f][1]+1;
				p[i]=true;
			}
		}
		f++;
	}
}
int main(){
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	bfs();
	return 0;
}
