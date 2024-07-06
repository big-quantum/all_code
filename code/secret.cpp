#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
string text1,text2;
int main(){
	cin>>text1>>text2;
	for(int i=1;i<=text1.size();i++){
		for(int j=1;j<=text2.size();j++){
			if(text1[i-1]==text2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]); 
		}
	} 
	cout<<dp[text1.size()][text2.size()]<<endl;
	return 0;
}
