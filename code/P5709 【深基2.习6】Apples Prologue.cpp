#include<bits/stdc++.h>
using namespace std;
int m,t,s;
int main(){
	cin>>m>>t>>s;
	if(t==0){
		cout<<0<<endl;
		return 0;
	}
	else if(s%t==0) m=max(m-s/t,0);
		 else m=max(m-s/t-1,0);
	cout<<m<<endl;
} 
