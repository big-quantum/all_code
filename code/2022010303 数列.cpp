#include<bits/stdc++.h>
using namespace std;
long long n,a=1,b=1;
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		b=b*2;
		a=a+b;
	}
	cout<<n<<" "<<a<<endl;
	return 0;
} 
