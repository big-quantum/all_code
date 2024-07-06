#include<bits/stdc++.h>
using namespace std;
int n,a,number[20005];
bool flag;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>number[i];
	}
	for(int i=1;i<=n;i++){
		if(number[i]!=0){
			for(int j=i+1;j<=n;j++){
				if(number[i]==number[j]) number[j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(number[i]!=0) cout<<number[i]<<" ";
	}
	return 0;
}
