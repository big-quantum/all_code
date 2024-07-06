#include<bits/stdc++.h>
using namespace std;
int n,s,f[105],ans;
struct node{
	int x,y,t;
}a[5005];
bool cmp(node a,node b){
	if(a.t<b.t) return true;
	else return false;
}
int main(){
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].t;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			if(j!=0&&f[j]==0) continue; 
			int x1=a[i].x,x2=a[j].x,y1=a[i].y,y2=a[j].y;
			if(double(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)))<=(a[i].t-a[j].t)*s) f[i]=f[j]+1;
		}
		ans=max(ans,f[i]); 
	}
	cout<<ans<<endl;
	return 0;
}
