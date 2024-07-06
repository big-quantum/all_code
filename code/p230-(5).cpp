#include<bits/stdc++.h>
using namespace std;
int ans,j;
char s[15],number[15];
int main(){
	for(int i=0;i<=12;i++)
		s[i]=getchar();
	for(int i=0;i<=12;i++){
		if(s[i]!='-'){
			if(s[i]=='X'){
				number[9]=10;
				break;
			}
			number[j]=s[i]-'0';
			j++;
			if(j!=10) ans=ans+number[j-1]*j;
		}
	} 
	ans=ans%11;
	if(number[9]==ans||number[9]==10&&ans=='X') cout<<"Right"<<endl;
	else {
		for(int i=0;i<=11;i++){
			putchar(s[i]);
		}
		if(ans==10) cout<<'X'; 
		else cout<<ans;
	}
	return 0;
} 
// 0-670-82162-0
// 0-670-83162-0
