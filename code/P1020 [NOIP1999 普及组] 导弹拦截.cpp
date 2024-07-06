#include<bits/stdc++.h>
using namespace std;
int n=1,a[100005],dp1[100005],dp2[100005];
int main(){
	while(cin>>a[n]) n++;
	n--;
	int len1=1,len2=1;
	dp1[1]=a[1];
	dp2[1]=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]<=dp1[len1]){
			len1++;
			dp1[len1]=a[i];
		} else {
			*upper_bound(dp1+1,dp1+len1+1,a[i],greater<int>())=a[i];
		}
		if(a[i]>dp2[len2]){
			len2++;
			dp2[len2]=a[i];
		} else {
			*lower_bound(dp2+1,dp2+len2+1,a[i])=a[i];
		}
	}
	cout<<len1<<endl;
	cout<<len2<<endl;
	return 0;
}
