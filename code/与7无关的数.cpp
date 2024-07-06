#include<bits/stdc++.h>
using namespace std;
int n,a,b,i,s;
int main(){
	cin>>n;
	for(i=1;i<=n;i++)
	if(i%7!=0){
		a=i%10;
		b=i/10 %10;
		if(a!=7&&b!=7)
			s+=i*i;
	}
	cout<<s<<endl; 
	return 0;
}
