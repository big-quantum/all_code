#include<bits/stdc++.h>
using namespace std;
int n,m,num[10],len,ans; 
bool flag[10];
void dfs(int ner,int lenk){	
	if(lenk==len+1){
		//cout<<ner<<endl;
		if(ner%n==0){
			ans++;
		}
		return;
	}
	for(int i=1;i<=len;i++){
		if(!flag[i]){
			flag[i]=true;
			dfs(ner*10+num[i],lenk+1);
			flag[i]=false;
		}
	}
	return;
} 
int main(){
	cin>>n>>m;
	while(m!=0){
		len++;
		num[len]=m%10;
		m=m/10;
	} 
	for(int i=1;i<=len/2;i++){
		swap(num[i],num[len-i+1]);
	}
	dfs(0,1);
	cout<<ans<<endl;
	return 0;
} 
