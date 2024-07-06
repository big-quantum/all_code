#include<bits/stdc++.h>
using namespace std;
int a,b,c,n;
int main(){
	cin>>n;
	a=n%10;
	b=n/10%10;
	c=n/100;
	cout<<100*a+10*b+c<<endl;
	return 0;
} 
