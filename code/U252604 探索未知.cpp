#include<bits/stdc++.h>
using namespace std;
long long n,opt,a[1005],b[1005],ansa,ansb=1;
long long gcd(long long a,long long b){
    long long t=b;
    while(b){
        b=a%b;
        a=t;
        t=b;
    }
    return a;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>opt;
		if(opt==1){
			ansa=ansa*b[i]+a[i]*ansb;
			ansb=ansb*b[i];
			long long gcda=gcd(abs(ansa),ansb);
			ansa=ansa/gcda;
			ansb=ansb/gcda;
		} else {
			ansa=ansa*b[i]-a[i]*ansb;
			ansb=ansb*b[i];
			long long gcda=gcd(abs(ansa),ansb);
			ansa=ansa/gcda;
			ansb=ansb/gcda;
		} 
	}
	if(ansb==1) cout<<ansa<<endl;
	else cout<<ansa<<"/"<<ansb<<endl;
	return 0;
} 
