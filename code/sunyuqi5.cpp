#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,f;
int main() {
	cin >> d ;
	a = d % 10;
	b = d / 10 % 10;
	c = d / 100;
	f=a*a*a+b*b*b+c*c*c;
	if(f==d) cout<<"yes"<<endl;
	else cout<<"no" <<endl; 
	return 0;
}
