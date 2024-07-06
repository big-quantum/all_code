#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005],n,k,cnt,ans;
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	} 
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		//cout<<a[i]<<" "; 
		if(a[i]==a[i+1]) cnt++;
		else {
			cnt++;
			if(cnt>=k){
				cnt=0;
				ans++;
				b[i]=a[i];
				
			}
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		if(b[i]!=0){
			printf("%d ",b[i]);
		}
	}
	return 0;
} 
