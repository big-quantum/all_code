#include<bits/stdc++.h>
using namespace std;
int vul,d,ans,s;
int main(){
	cin>>vul>>d;
	for(int i=1;i<=vul;i++){
	if(vul<=0)
	ans--;
	break;
	vul-i;
	ans=ans+i+1;
	}
	cout<<ans<<endl;
	return 0;
}
