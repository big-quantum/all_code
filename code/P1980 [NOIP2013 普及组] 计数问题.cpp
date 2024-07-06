#include<bits/stdc++.h>
using namespace std;
int n,x,ans;
int check(int a){
	int num=0;
	while(a!=0){
		if(a%10==x) num++;
		a=a/10;
	}
	return num;
}
int main(){
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		ans+=check(i);
	}
	cout<<ans<<endl;
	return 0;
} 
