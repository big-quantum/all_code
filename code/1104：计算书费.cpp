#include<bits/stdc++.h>
using namespace std;
int books[15];
float ans,money[15]={28.9,32.7,45.6,78,35,86.2,27.8,43,56,65};
int main(){
	for(int i=0;i<10;i++){
		cin>>books[i];	
	}
	for(int i=0;i<10;i++){
		ans=ans+books[i]*money[i];	
	}
	cout<<ans<<endl;
	return 0;
}
