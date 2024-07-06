#include<bits/stdc++.h>
using namespace std;
int n,number[10005],sq,len=1,tmp;
int main(){
	cin>>n;
	tmp=n;
	for(int i=2;i<=n;i++){
		while(n%i==0){
			n=n/i;
			number[len]=i;
			len++; 
		}
	}
	cout<<tmp<<"=";
	for(int i=1;i<len-1;i++){
		cout<<number[i]<<"*";
	}
	cout<<number[len-1];
	return 0;
} 
