#include<bits/stdc++.h>
using namespace std;
long long a[1000005],b[1000005][2],n,maxx=-1,minn=1000000009,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>=maxx) {
			maxx=a[i];
			b[i][0]=maxx;
		} else b[i][0]=maxx;
	} 
	for(int i=n;i>=1;i--){
		if(a[i]<minn){
			minn=a[i];
			b[i][1]=minn;
		} else b[i][1]=minn;
		if(b[i-1][0]<b[i][1]) ans++;
	} 
	cout<<ans<<endl;
	return 0;
} 
