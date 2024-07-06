#include<bits/stdc++.h>
using namespace std;
int n;
string data[15],ans[15]; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>data[i];
		int len=data[i].size(),number=0;
		for(int j=0;j<len;j++){
			if(data[i][j]>='0'&&data[i][j]<='9'){
			 	number=number*10+data[i][j]-'0';
			} else {
				if(data[i][j]=='-'&&number!=0){
					ans[i].push_back(char(number+'A'-1));
					number=0;
				}
				if(data[i][j]=='#'){
					if(number!=0){
						ans[i].push_back(char(number+'A'-1));
						number=0;
					}
					ans[i].push_back(' ');
				}
			}
		} 
		if(number!=0) ans[i].push_back(char(number+'A'-1));
		cout<<ans[i];
		if(i!=n) cout<<endl; 
	} 
	return 0;
} 
