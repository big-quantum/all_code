#include<bits/stdc++.h>
using namespace std;
char op[10],ad[30];
struct address{
	int a,b,c,d,e;
} s[1005],c[1005];
int n,cnt,;
bool flag=true,f[1005];
int main(){
	//freopen("network.in","r",stdin);
	//freopen("network.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>op>>ad;
		if(op[0]=='S'){
			flag=true;
			int len=strlen(ad);
			for(int j=0;j<len;j++){
				if(ad[j]!='.'){
					if(ad[j]==':'){
						cnt++;
						flag=false;
						continue;
					}
					if(cnt==0){
						s[i].a=s[i].a*10+(ad[j]-'0');
						continue;
					}
					if(cnt==1){
						s[i].b=s[i].b*10+(ad[j]-'0');
						continue;
					}
					if(cnt==2){
						s[i].c=s[i].c*10+(ad[j]-'0');
						continue;
					}
					if(cnt==3){
						s[i].d=s[i].d*10+(ad[j]-'0');
						continue;
					}
					if(cnt==4){
						s[i].e=s[i].e*10+(ad[j]-'0');
						continue;
					}
				} else {
					cnt++;
				}
			}
			cnt=0;
			if(s[i].a>255||s[i].a<0||s[i].b>255||s[i].b<0||s[i].c>255||s[i].c<0||s[i].d>255||s[i].d<0||s[i].e>65535||s[i].e<0||flag){
				cout<<"ERR"<<endl;
				f[i]=true;
				continue;
			}
			flag=true;
			for(int j=1;j<=i;j++){
				if(s[i].a==s[j].a&&s[i].b==s[j].b&&s[i].c==s[j].c&&s[i].d==s[j].d&&s[i].e==s[j].e&&j!=i){
					cout<<"FAIL"<<endl;
					f[i]=true;
					flag=false;
					break;
				}
			}
			if(flag){
				cout<<"OK"<<endl;
			}
			cnt=0;
		} else {
			f[i]=true;
			flag=false;
			int len=strlen(ad);
			for(int j=0;j<len;j++){
				if(ad[j]!='.'){
					if(ad[j]==':'){
						cnt++;
						flag=true;
						continue;
					}
					if(cnt==0){
						c[i].a=c[i].a*10+(ad[j]-'0');
						continue;
					}
					if(cnt==1){
						c[i].b=c[i].b*10+(ad[j]-'0');
						continue;
					}
					if(cnt==2){
						c[i].c=c[i].c*10+(ad[j]-'0');
						continue;
					}
					if(cnt==3){
						c[i].d=c[i].d*10+(ad[j]-'0');
						continue;
					}
					if(cnt==4){
						c[i].e=c[i].e*10+(ad[j]-'0');
						continue;
					}
				} else {
					cnt++;
				}
			}
			cnt=0;
			if(c[i].a>255||c[i].a<0||c[i].b>255||c[i].b<0||c[i].c>255||c[i].c<0||c[i].d>255||c[i].d<0||c[i].e>65535||c[i].e<0||!flag){
				cout<<"ERR"<<endl;
				continue;
			}
			flag=false;
			for(int j=1;j<=i;j++){
				if(c[i].a==s[j].a&&c[i].b==s[j].b&&c[i].c==s[j].c&&c[i].d==s[j].d&&c[i].e==s[j].e&&!f[j]){
					cout<<j<<endl;
					flag=true;
					break;
				}
			}
			if(!flag){
				cout<<"FAIL"<<endl;
			}
			
		}
	}
	return 0;
}
