#include<bits/stdc++.h>
using namespace std;
int w,n,p[30005],ans;
int main(){
	cin>>w>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	sort(p+1,p+n+1);
	int i=0,j=n;
	while(i<=j){
		if(p[i]+p[j]<=w) {
			i++;
			j--;
			ans++;
		} else {
			j--;
			ans++;
		}
	} 
	cout<<ans<<endl;
	return 0;
}
