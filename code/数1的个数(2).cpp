#include<bits/stdc++.h>
using namespace std;
int n,ans,b;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		b=i;
		while(b/10!=0){
			if(b%10==1)
				ans++;
			b=b/10;
		}
		if(b==1)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
