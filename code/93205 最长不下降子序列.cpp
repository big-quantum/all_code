#include<bits/stdc++.h>
using namespace std;
int a[105],f[105],n=1,ans;
int main(){
	while(cin>>a[n]){
		f[n]=1;
		n++;
	}
	n--;
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i]>=a[j]) f[i]=max(f[j]+1,f[i]);
		} 
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i]); 
	}
	cout<<ans<<endl;
}
