#include<bits/stdc++.h>
using namespace std;
int n,a[205],b; 
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>b;
		a[b]++;	
	} 
	for(int i=1;i<=200;i++){
		if(a[i]!=0){
			for(int j=1;j<=a[i];j++){
		    	cout<<i<<" ";
			}	
		}
	}
	cout<<endl;	
    return 0;
}
