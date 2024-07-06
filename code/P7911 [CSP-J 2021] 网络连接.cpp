#include<bits/stdc++.h>
using namespace std;
bool check(string ip){
	int a,b,c,d,e;
	int cnt=sscanf(ip.c_str(),"%d.%d.%d.%d:%d",&a,&b,&c,&d,&e);
	if(cnt!=5) return false;
	if(a>255||a<0) return false;
	if(b>255||b<0) return false;
	if(c>255||c<0) return false;
	if(d>255||d<0) return false;
	if(e>65535||e<0) return false;
	char s[35];
	sprintf(s,"%d.%d.%d.%d:%d",a,b,c,d,e);
	if(string(s)!=ip) return false;
	return true;
}
int n;
string op,ad;
map<string,int> server;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>op>>ad;
		if(!check(ad)){
			printf("ERR\n");
			continue;
		}
		if(op=="Server"){
			if(server[ad]){
				printf("FAIL\n");
			} else {
				server[ad]=i;
				printf("OK\n");	
			}
		} else {
			if(server[ad]!=0) printf("%d\n",server[ad]);
			else printf("FAIL\n");
		}
	} 
	return 0;
}
