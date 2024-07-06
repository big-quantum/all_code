#include<bits/stdc++.h>
using namespace std;
int n,pep[105],dpr[105],dpl[105],ans=INT_MAX;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>pep[i];
	}
	for(int i=1;i<=n;i++){
		dpr[i]=1;
		for(int j=1;j<i;j++){
			if(pep[j]<pep[i]) dpr[i]=max(dpr[j]+1,dpr[i]);
		}
	}
	for(int i=n;i>=1;i--){
		dpl[i]=1;
		for(int j=n;j>i;j--){
			if(pep[j]<pep[i]) dpl[i]=max(dpl[j]+1,dpl[i]);
		}
	}
	for(int i=1;i<=n;i++){
		ans=min(ans,n-dpl[i]-dpr[i]+1);
	}
	cout<<ans<<endl;
	return 0;
}
//https://oj.czos.cn/p/1277
