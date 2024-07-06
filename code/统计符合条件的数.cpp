#include<bits/stdc++.h>
using namespace std;
long long n,ans,cnt;
bool check(long long a){
	int num[15],cnt=0;
	while(a!=0){
		cnt++;
		num[cnt]=a%10;
		a=a/10;
	}
	
	if(cnt%2!=0) return false;
	for(int i=cnt;i>=1;i--){
		if(num[i]!=num[cnt-i]) return false;
	}
	return true;
}
int main(){
	//cin>>n;
	for(long long i=11;i<=1000000000000;i++){
		if(check(i)){
			cout<<i<<" ";
		}
	}
	return 0; 
} 
