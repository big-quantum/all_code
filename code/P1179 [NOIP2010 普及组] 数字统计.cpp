#include<bits/stdc++.h>
using namespace std;
int l,r,ans;
int check(int a){
	int num=0;
	while(a!=0){
		if(a%10==2) num++;
		a=a/10;
	}
	return num;
} 
int main(){
	cin>>l>>r;
	for(int i=l;i<=r;i++){
		ans+=check(i); 
	}
	cout<<ans<<endl;
	return 0;
}
