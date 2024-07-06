#include<bits/stdc++.h>
using namespace std;
int a[50],ans;
int main(){
	for(int i=1;i<=10;i++){
		int b;
		cin>>b;
		a[b%42]--;
	}
	for(int i=0;i<=45;i++){
		if(a[i]!=0) ans++;
	}
	cout<<ans<<endl;
	return 0;
} 
