#include<bits/stdc++.h>
using namespace std;
long long n,ans;
int main(){
	cin>>n;
	for(int i=1;i<=n-2;i++){
		for(int j=i;j<=n-2;j++){
			int k=n-i-j; 
			if(i+j>k&&i+k>j&&k+j>i&&j<=k) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
