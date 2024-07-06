#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int flag=a[1],cnt=1;
	for(int i=2;i<=n;i++){
		if(a[i]==flag){
			cnt++;	
		} else {
			cout<<flag<<" "<<cnt<<endl;
			flag=a[i];
			cnt=1;
		}
	}
	cout<<flag<<" "<<cnt<<endl;
	return 0;
}
