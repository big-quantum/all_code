#include<bits/stdc++.h>
using namespace std;
int n,num[10]={6,2,5,5,4,5,6,3,7,6},ans;
int left(int a){
	int tmp;
	do{
		tmp+=num[a%10];
		a/=10;
	} while(a!=0);
	return tmp;
}
int main(){
	cin>>n;
	n-=4;
	for(int i=0;i<=1200;i++){
		for(int j=0;j<=1200;j++){
			int tmp=i+j;
			if(left(i)+left(j)+left(tmp)==n) {
				ans++;
				cout<<i<<" "<<j<<" "<<tmp<<" "<<left(i)+left(j)+left(tmp)<<endl;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
