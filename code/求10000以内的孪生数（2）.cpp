#include<bits/stdc++.h>
using namespace std;
int a,num;
int ysh(int n){
	int i,s=0;
	for(i=1;i*i<=n;i++) {
		if(n%i==0)
			if(i*i==n)
				s+=i;
			else
				s+=i+n/i;
	}
	return s-n;
}
int main(){
	for(int i=1;i<=10000;i++){
		if(ysh(ysh(i))==i&&ysh(i)!=i){
			num++;
			if(num==1)
				cout<<i<<" "<<ysh(i)<<endl; 
			if(num==2) 
				num=0;
		}
	}
}
