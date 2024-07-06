#include<bits/stdc++.h>
using namespace std;
int s[50005],n,num[50005],cnt[10][3],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		s[i]=(s[i-1]+num[i])%7;
		if(cnt[s[i]][1]!=0) cnt[s[i]][1]=i;
		else cnt[i]][2]=i;
	}
	for(int i=1;i<=n;i++){
		cout<<s[i]<<" ";
	}
	for(int i=0;i<7;i++) ans=max(ans,cnt[i][2]-cnt[i][1]);
	cout<<ans<<endl;
	return 0;
}
