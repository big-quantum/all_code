#include<bits/stdc++.h>
using namespace std;
int n1,n2,ans=INT_MAX,cnt=1;
string s;
bool flag;
bool check(int a){
	int len=sqrt(a)+1;
	bool flag=false;
	for(int i=2;i<=len;i++){
		if(a%i==0) flag=true;
	}
	if(flag) return false;
	else return true;
}
int main(){
	cin>>s;
	int len=s.size();
	while(cnt!=len){
		for(int i=0;i<cnt;i++){
			n1=n1*10+int(s[i])-'0'; 
		} 
		for(int i=cnt;i<len;i++){
			n2=n2*10+int(s[i])-'0';
		} 
		if(check(n1+n2)){
			ans=min(ans,n1+n2);
			flag=true;
		}
		n1=0;
		n2=0;
		cnt++;
	}
	if(flag) cout<<ans<<endl;
	else cout<<-1<<endl;
	return 0;
} 
