#include<bits/stdc++.h>
using namespace std;
char a[10],b[10];
int cnta=1,cntb=1;
int main(){
	cin>>a>>b;
	int lena=strlen(a),lenb=strlen(b);
	for(int i=0;i<lena;i++){
		cnta=cnta*(a[i]-'A'+1);
	}
	for(int i=0;i<lenb;i++){
		cntb=cntb*(b[i]-'A'+1);
	}
	cnta=cnta%47;
	cntb=cntb%47;
	if(cnta==cntb) cout<<"GO"<<endl;
	else cout<<"STAY"<<endl;
	return 0;
} 
