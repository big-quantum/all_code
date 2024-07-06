#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005],n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	} 
	for(int i=n;i>=1;i--){
		long long cnt1=b[i]*i,cnt2=b[i-1]*(i-1);
		a[i]=cnt1-cnt2;
	}
	for(int i=1;i<=n;i++){
		printf("%lld ",a[i]);
	}
	return 0;
} 
