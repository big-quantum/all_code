#include<bits/stdc++.h>
using namespace std;
long long n,ans;
int main(){
	cin>>n;
	n=n-3;
	for(int i=n;i>=0;i--){
		for(int j=n-i;j>=0;j--){
			int k=n-i-j; 
			if(i*20+j*10+k*5==65) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
