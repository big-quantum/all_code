#include<bits/stdc++.h>
using namespace std;
int n=1;
bool flag=true;
char s[10005];
int main(){
	freopen("one.in","r",stdin);
	freopen("one.out","w",stdout);
	while((s[n]=getchar())!='\n')
		n++;
	n--;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(s[i]==s[j]){
				flag=false;
				break;
			} 
		}
		if(flag==true){
			cout<<s[i]<<endl;
			break;
		}
		flag=true;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
