#include<bits/stdc++.h>
using namespace std;
long long n,a[10005],sum;
int main(){
	cin>>n;
	a[0]=n;
	for(int i=1;n!=1;i++){
		if(n%2==0){
			n=n/2;
			a[i]=n;
		} else { 
			n=n*3+1;
			a[i]=n;
		}
		sum++;
	}
	for(int i=sum;i>=0;i--){
		cout<<a[i]<<" ";
	}
	return 0;
}
