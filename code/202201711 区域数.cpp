#include<bits/stdc++.h>
using namespace std;
int n,ans=2;
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		ans+=i*2; 
	}
	cout<<ans<<endl;
	return 0;
}
