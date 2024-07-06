#include<bits/stdc++.h>
using namespace std;
int apple[11],i,h,ans;
int main(){
	for(i=1;i<=10;i++)
		cin >> apple[i];
	cin >> h;
	h = h + 30;
	for(i=1;i<=10;i++)
		if(h>=apple[i]) 
			ans++;
	cout << ans << endl;
	return 0;	
}