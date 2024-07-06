#include<bits/stdc++.h>
using namespace std;
int n,ans,k,s,maxd;
struct node{
	int m,b;
}stone[300005];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int d,tmpm;
		scanf("%d%d",&d,&tmpm);
		if(d>maxd) maxd=d;
		stone[d].m+=tmpm;
	}
	for(int i=1;i<=maxd+1;i++){
		if(stone[i].b==0&&stone[i].m>k){
			stone[i].m-=k;
			ans+=k;
			stone[i+1].b=stone[i].m;
		} else {
			if(stone[i].b>k){
				ans+=k;
				stone[i+1].b=stone[i].m;
			} else {
				ans+=stone[i].b;
				int tmpk=k;
				tmpk-=stone[i].b;
				stone[i].b=0;
				if(stone[i].m>tmpk){
					stone[i].m-=tmpk;
					ans+=tmpk;
					stone[i+1].b=stone[i].m;
				} else {
					ans+=stone[i].m;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
