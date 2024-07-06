#include<bits/stdc++.h>
using namespace std;
int n,m[20]={1};
void gets(){
	for(int i=0;i<=18;i++){
		m[i+1]=m[i]*2;
	}
} 
void search(int n){
	if(n!=0){
		int cnt=0;
		cout<<2;
		while(n>=m[cnt]){
			cnt++;
		} 
		cnt--;
		if(cnt<3&&cnt!=1) cout<<"("<<cnt<<")";
		if(cnt>=3){
			cout<<"(";
			search(cnt);
			cout<<")";
		}
		if(n-m[cnt]!=0){
			cout<<"+";
			search(n-m[cnt]);
		}
	} else {
		return;
	}
}
int main(){
	gets();
	cin>>n;
	search(n);
	return 0; 
}
