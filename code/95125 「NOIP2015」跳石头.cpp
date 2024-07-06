#include<bits/stdc++.h>
using namespace std;
int m,n,l,stone[50005];
int first=1,last,mid,ans;
int main(){
	cin>>l>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>stone[i];
	}
	last=l;
	stone[n+1]=l;
	while(first<=last){
		mid=(first+last)/2;
		int cnt=0,i=0,now=0;
		while(i<n+1){
			i++;
			if(stone[i]-stone[now]<mid) cnt++;
			else now=i;
		}
		if(cnt>m) last=mid-1;
		else{
			ans=mid;
			first=mid+1;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
