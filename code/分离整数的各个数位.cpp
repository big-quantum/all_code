#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	while(n){
		if(n<10)cout<<n<<endl;
		else cout<<n%10<<" ";
		n=n/10;
	}
	return 0;
}
