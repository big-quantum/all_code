#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int main(){
	cin>>n;
	b=n;
	while(b!=0){
		a=a*10+b%10;
		b=b/10;
	}
	if(a==n){
		cout<<n<<endl;
	} else {
		cout<<"-1"<<endl;
	}
	return 0;
} 
