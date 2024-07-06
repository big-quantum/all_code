#include<bits/stdc++.h>
using namespace std;
int n,num[10005],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>num[i];
	for(int i=1;i<n;i++)
	 for(int j=1;j<=n-i;j++)
	 	if(num[j]>num[j+1]){
	 		swap(num[j],num[j+1]);
	 		ans++;
		 }
	cout<<ans<<endl;
	return 0;
}
