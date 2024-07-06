#include<bits/stdc++.h>
using namespace std;
int n,number[100005],ans,a1=1,a2,a3,maxx=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>number[i];
	}
	for(int i=a1;i<=n;i++){
		ans=1;
		a2=a1+1;
		for(int j=1;j<=n;j++){
		if(ans>maxx){
				maxx=ans;	
			}
			if(number[a1]==number[a2]){
				ans++;
				a1=a2;
				a2++;	
			} else {
				a1++;
				break;
			}
			
		}
		
	}
	cout<<maxx<<endl;
	return 0;
}
