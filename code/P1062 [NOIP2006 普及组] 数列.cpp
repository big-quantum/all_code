#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,f;
int a[500];
int main(){
	cin>>k>>n;
	int y=0;
	while(n!=0){
        y++;
        a[y]=n%2;
        n=n/2;
   }
    int cnt=y;
    while(cnt!=0){
		f=f*k;
    	if(int(a[cnt])) f+=int(a[cnt]);
		cnt--;
	}
	cout<<f<<endl;
	return 0;
} 
