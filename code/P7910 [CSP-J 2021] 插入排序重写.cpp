#include<bits/stdc++.h>
using namespace std;
struct node{
	long long val,num;
} a[8005];
long long n,q,x,v,pos[8005],ll;
bool cmp(node a,node b){
	if(a.val==b.val) return a.num<b.num;
	else return a.val<b.val;
} 
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].val);
		a[i].num=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		pos[a[i].num]=i;
	}
	for(int i=1;i<=q;i++){
		scanf("%lld",&ll);
		if(ll==1){
			scanf("%lld%lld",&x,&v);
			a[pos[x]].val=v;
			for(int j=n;j>=2;j--){
				if(cmp(a[j],a[j-1])){
					swap(a[j],a[j-1]);
				}
			}
			for(int j=2;j<=n;j++){
				if(cmp(a[j],a[j-1])){
					swap(a[j],a[j-1]);
				}
			}
			for(int i=1;i<=n;i++){
				pos[a[i].num]=i;
			}
		} else {
			scanf("%lld",&x);
			printf("%lld\n",pos[x]);
		}
	}
	return 0;
}
