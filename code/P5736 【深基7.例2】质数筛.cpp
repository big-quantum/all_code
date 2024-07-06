#include<bits/stdc++.h>
using namespace std;
int n,a[105];
bool number[105]; 
bool check(int n){
	if (n < 2)
		return false;
	for(int i = 2;i < n;i++)
		if (n % i == 0)
			return false;
	return true;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(check(a[i])){
			number[i] = true;
		}
	} 
	for(int i=1;i<=n;i++){
		if(number[i]==true) cout<<a[i]<<" ";
	}
} 
