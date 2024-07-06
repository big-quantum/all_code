#include<bits/stdc++.h>
using namespace std;
int month[15]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main(){
	int n,m,s,ans=0,k;
	cin>>n>>m;
	for(int i=1;i<=12;i++){
		for(int j=1;j<=month[i];j++){
			k=(j%10)*1000+(j/10)*100+(i%10)*10+(i/10);
			s=k*10000+i*100+j;
			if(s<n||s>m) continue;
			ans++; 
		}
	} 
	cout<<ans<<endl;
	return 0; 
} 
