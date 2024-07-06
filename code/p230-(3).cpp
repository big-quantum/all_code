#include<bits/stdc++.h>
using namespace std;
int n,x,ans;
char s[255];
int main(){
	s[n]=getchar();
	while(1){
		while(s[n]!='+'&&s[n]!='\n'){
			x=x*10+s[n]-'0'; 
			++n;
			s[n]=getchar();
		}
		ans=ans+x;
		if(s[n]=='\n') break; 
		x=0;
		s[++n]=getchar();
	}		
	cout<<ans<<endl;
} 
