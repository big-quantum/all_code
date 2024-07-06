#include<bits/stdc++.h>
using namespace std;
string s;
int cnt,ans;
int main(){
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	if (s[i]=='H'||s[i]=='h'||s[i]=='L'||s[i]=='l'||s[i]=='O'||s[i]=='o'||s[i]=='I'||s[i]=='i')
	cnt++;
	else{
		if(cnt>ans)ans=cnt;
		cnt = 0;
	}
	ans=max(ans,cnt);	
	cout<<ans<<endl;
	return 0;	
}
