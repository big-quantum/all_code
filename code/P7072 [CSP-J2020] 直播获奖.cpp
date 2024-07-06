#include<bits/stdc++.h>
using namespace std;
int n,w,a[605],num;
int main(){
	cin>>n>>w;
	for(int i=1;i<=n;i++){
		cin>>num;
		a[num]++;
		int grade=max(1,i*w/100),p=0; 
		for(int j=600;j>=0;j--){
			if(a[j]!=0){
				p+=a[j];
				if(p>=grade){
					 cout<<j<<" ";
					 break;
				}
			}
		}
	} 
	return 0;
}
