#include<bits/stdc++.h>
using namespace std;
int n[1005],i;
void coin(int a) {
	int b=0,sum=0;
	for(int i=1;i>=1;i++){
		for(int j=1;j<=i;j++){
			b=b+1;
			sum=sum+i;
			if(b>=a) break;
		}
		if(b>=a) break;
	}
	cout<<sum<<endl;;
}
int main(){
	do {
		i++;
		cin>>n[i];
	} while(n[i]!=0);
	for(int j=1;j<i;j++){
		coin(n[j]);
	}
	return 0;
}
