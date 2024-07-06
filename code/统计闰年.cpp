#include<bits/stdc++.h>
using namespace std;
int x,y,ans;
int main(){
	cin>>x>>y;
	for(int i=x;i<=y;i++)
		if(i%100!=0&&i%4==0||i%400==0)
			ans++;
	cout<<ans<<endl;
	return 0;
}
