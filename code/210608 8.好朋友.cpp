#include<bits/stdc++.h>
using namespace std;
int s,a,b;
int y(int s){
	int ans=1;
	int tmp=sqrt(s); 
	for(int i=2;i<=tmp;i++){
		if(s%i==0){
			ans+=i;
			if(s/i!=tmp) ans=ans+s/i; 
		}
	}
	return ans;
}
int main(){
	cin>>s;
	for(int a=s;a<=300000;a++){
		int b=y(a);
		int i=y(b);
		if(a==i&&a!=b&&b>=s){
			cout<<a<<" "<<b<<endl;	
			break; 
		}
	}
	return 0;
}
