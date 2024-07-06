#include<bits/stdc++.h>
using namespace std;
int n;
bool a[105];
int main(){
	cin>>n;
	cout<<n<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				a[j]=(!a[j]);
			}
			cout<<int(a[j]);
		}
		cout<<endl;
	}
	return 0;
} 
