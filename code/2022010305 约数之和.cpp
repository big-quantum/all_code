#include<bits/stdc++.h>
using namespace std;
long long n,a;
int main(){
	cin>>n;
	for(int i=1;i<=sqrt(n);i++){
		if(n%i==0){
			a+=i;
			if(i!=n/i) a=a+n/i;
		}
	}
	cout<<a<<endl;
	return 0;
} 
