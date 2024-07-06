#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	for(int j=1;j<=n;j++){
		for(int i=1;i<=j - 1;i++)
			cout<<setw(5)<<"";
		for(int i = 1;i <= n + 1 - j;i++)
			cout << setw(5) << i;
		cout<<endl;
	}
} 
