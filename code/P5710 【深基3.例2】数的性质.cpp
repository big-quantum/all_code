#include<bits/stdc++.h>
using namespace std;
int a,one,two,num;
int main(){
	cin>>a;
	if(a%2==0) one=1;
	if(4<a&&a<=12) two=1;
	num=one+two;
	if(num==2) cout<<1<<" "; 
	else cout<<0<<" ";
	if(num==1||num==2) cout<<1<<" "; 
	else cout<<0<<" ";
	if(num==1) cout<<1<<" "; 
	else cout<<0<<" ";
	if(num==0) cout<<1<<" "; 
	else cout<<0<<" ";
	return 0;	
}

