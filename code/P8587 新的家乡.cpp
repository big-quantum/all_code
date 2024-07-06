#include<bits/stdc++.h>
using namespace std;
int n,h[6005],maxh,ans[18662],ansn,ansh;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		maxh=max(maxh,a);
		h[a]++;
	}
	for(int i=1;i<=maxh;i++){
		for(int j=1;j<=i;j++){
			if(i==j){
				if(h[i]>1) ans[i+j]+=(h[i]/2);
			} else {
				if(h[i]>0&&h[j]>0){
					ans[i+j]+=min(h[i],h[j]);	
				}
			}
		}
	}
	int maxxh=maxh*2;
	for(int i=1;i<=maxxh;i++){
		ansn=max(ansn,ans[i]);
	}
	for(int i=1;i<=maxxh;i++){
		if(ans[i]==ansn){
			ansh++;
		}
	}
	cout<<ansn<<" "<<ansh<<endl;
	return 0; 
}
