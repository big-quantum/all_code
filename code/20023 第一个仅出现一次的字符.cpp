#include<bits/stdc++.h>
using namespace std;
int n;
bool flag;
string s;
int main(){
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		flag=true;
		for(int j=0;j<n;j++){
			if(s[i]==s[j]&&i!=j){
				flag=false;
				break;
			}
		}
		if(flag){
			cout<<s[i]<<endl;
			break;
		}
	}
	return 0;
} 
