#include<bits/stdc++.h>
using namespace std;
#define Maxn 1000000 + 5
int h[Maxn],k,n,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	scanf("%d",&k);
	for(int i=1;i<=n;i++)
		if(h[i]==k)
			ans++;
	cout<<ans<<endl;
	return 0;
}
