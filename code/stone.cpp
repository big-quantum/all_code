#include<bits/stdc++.h>
using namespace std;
int n,opt[10000005];
long long ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		opt[i]=1;
		if(i>=1)
			opt[i] = min(opt[i-1] + 1,opt[i]);
		if(i>=5)
			opt[i] = min(opt[i-5] + 1,opt[i]);
		if(i>=7)
			opt[i] = min(opt[i-7] + 1,opt[i]);
	}
	cout<<opt[n]<<endl;
	return 0;
}
