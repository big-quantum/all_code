#include<bits/stdc++.h>
using namespace std;
int n,num;
string s;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		num = s[s.size() - 1] - '0';
		if(num%2==0)
			cout<<"even"<<endl;
		else
			cout<<"odd"<<endl;
	}
	return 0;
}
