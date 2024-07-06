#include<bits/stdc++.h>
using namespace std;
int n,number[10005],Fmax=-1,ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>number[i];
		if(number[i]>Fmax) Fmax=number[i];
	}
	for(int i=0;i<=Fmax;i++){
		for(int j=1;j<=n;j++){
			if(number[j]==i) ans++;
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
