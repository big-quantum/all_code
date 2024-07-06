#include<bits/stdc++.h>
using namespace std;
int n,m,number[105],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>number[i];	
	}
	cin>>m;
	for(int i=1;i<=n;i++){
		if(number[i]==m){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
