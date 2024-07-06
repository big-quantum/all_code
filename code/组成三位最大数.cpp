#include<bits/stdc++.h>
using namespace std;
int a,b,c,n;
int main(){
	cin>>n;
	a=n%10;
	b=n/10%10;
	c=n/100;
	if(a<b) swap(a,b);
	if(a<c) swap(a,c);
	if(b<c) swap(b,c);
	cout<<a*100+b*10+c<<endl;
	return 0;
}
