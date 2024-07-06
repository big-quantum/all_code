#include<bits/stdc++.h>
using namespace std;
int n,x,y,a[200000],p[200005][2];
bool vis[400010];
void bfs(){
	int f=1;
	int l=1;
	p[f][0]=x;
	p[f][1]=0;
	vis[p[f][0]]=1;
	while (f<=l){
		if (p[f][0]==y){
			cout<<p[f][1]<<endl;
			return;
		}
		p[f][1]++;
		if (p[f][0]<y){
			p[f][0]+=a[p[f][0]];
			if(vis[p[f][0]]==0){
				l++;
				vis[p[f][0]]=1;
			}
		}
		if (p[f][0]-a[p[f][0]]>=1){
			p[f][0]-=a[p[f][0]];
			if(vis[p[f][0]]==0){
				l++;
				vis[p[f][0]]=1;
			}
		}
		f++;
	}
	cout<<-1<<endl;
}
int main(){
	cin>>n>>x>>y;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	bfs();
	return 0;
}
