#include<nits/stdc++.h>
using namespace std;
int n,cnt,Map[205][205];
string s;
int main(){
	while(cin>>s){
		for(int i=;i<s.size();i++)
		Map[cnt][j] = s[j] - '0';
		cnt++;
	}
	cout<<cnt+1;
	int last = 0,t=0;
	for(int i =0;i<cnt;i++)
		for(iny j =0;j<cnt;j++)
			if(Map[i][j] ==last)
				t++;
			else{
				cout<<" "<<t;
				t=1;
				last = 1-last;
			}
	return 0;
}
