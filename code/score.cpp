#include<bits/stdc++.h>
using namespace std;
int s[105],n;
string name[100];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>name[i]>>s[i];
	} 
	for(int i=1;i<n;i++){
		for(int j=1;j<=n-i;j++){
			if(s[j]>s[j+1]){
				swap(s[j],s[j+1]);
				swap(name[j],name[j+1]);
			} else if(s[j]==s[j+1]&&name[j].compare(name[j+1])==1){
				swap(s[j],s[j+1]);
				swap(name[j],name[j+1]);
			}
		} 
	}
	for(int i=1;i<=n;i++){
		cout<<name[i]<<endl;
	}
	return 0;
} 

