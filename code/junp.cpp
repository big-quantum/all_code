#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
	cin>>a>>b>>c;
	cout<<max(a-b-1,c-b-1)<<endl;
	return 0;
}
