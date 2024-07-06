#include<bits/stdc++.h>
using namespace std;
int n,x,num[100005];
long long ans;
int main(){
	cin>>n>>x;;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int i=2;i<=n;i++)
	if(num[i] + num[i-1]>x){
		int tmp=num[i]+num[i-1]-x;
		ans+=tmp;
		if(tmp>num[i]){
			tmp = tmp-num[i];
			num[i-1]=num[i-1]-tmp;
			num[i]=0;
		}
		else
			num[i]=num[i]-tmp;
	}
	cout<<ans<<endl;
	return 0;
}
