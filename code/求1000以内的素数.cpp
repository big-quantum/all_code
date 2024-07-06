#include<bits/stdc++.h>
using namespace std;
bool prime(int n){
	if(n<2) return false;
	for(int i=2;i*i<=n;i++)
		if(n%i==0) return false;
	return true;
}
int main(){
	for(int i=1;i<=1000;i++){
		if(prime(i)) cout<<i<<" ";
	}
}
