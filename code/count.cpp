#include<bits/stdc++.h>
using namespace std;
int c,ans;
int main(){
	cin>>c;
	for(int i=1;i<=c;i++)
		ans=ans+(i+1)*i/2;
	cout<<ans<<endl;
}
