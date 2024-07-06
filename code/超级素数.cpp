#include<bits/stdc++.h>
using namespace std;
int x,q[100005]={2,3,5,7},c[4]={1,3,7,9},f,r=4;
bool prime(int num){
	if(num<2) return false;
	else for(int i=2;i<=sqrt(num);i++){
		if(num%i==0) return false;
	}
	return true;
}
int main(){
	cin>>x;
	while(f<r){
		for(int k=0;k<4;k++){
			int nx=q[f]*10+c[k];
			if(prime(nx)&&nx<=x){
				q[r]=nx;
				r++;
			}
		}
		f++;
	} 
	cout<<r<<endl;
	for(int i=0;i<r;i++){
		cout<<q[i]<<endl;
	}
	return 0;
}

