#include<bits/stdc++.h>
using namespace std;
char n[15];
int ans;
int main(){
	cin>>n;
	for(int i=0;i<=8;i++)
		if(n[i]=='1'){
			ans++; 
		}
		cout<<ans<<endl;
	return 0;
} 
