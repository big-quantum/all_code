#include<bits/stdc++.h>
using namespace std;
int n,m,r[500005];
struct node{
	int d,s,t; 
}clas[500005];
/*inline int InP()
{
    int N=0;
    char C;
    C=getchar();
    while('0' <= C && C <= '9')
    N=N*10 + (C-'0') , C=getchar();
    return N;
}*/
void read(int& x){
    x=0;
    int y=1;
    char ch=getchar();
    while (ch<'0'||ch>'9'){
        if (ch=='-') y=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    x=x*y;
}
/*inline int read(){
    int num = 0;
    char c;
    bool flag = false;
    while ((c = getchar()) == ' ' || c == '\n' || c == '\r')
        if (c == '-') flag = true;
    	else num = c - '0';
    while (isdigit(c = getchar()))
    num = num * 10 + c - '0';
    return (flag ? -1 : 1) * num;
}*/
int main(){
	read(n);
	read(m);
	for(int i=1;i<=n;i++){
		read(r[i]);
	}
	for(int i=1;i<=m;i++){
		read(clas[i].d);
		read(clas[i].s);
		read(clas[i].t);
	}
	int l=1,r=m,mid;
	while(l<=r){
		mid=(l+r)/2;
		for(int i=l;i<=mid;i++){
			int si=clas[i].s;
			int ti=clas[i].t;
			int di=clas[i].d;
			for(int j=si;j<=ti;j++){
				if(r[j]<di){
					cout<<-1<<endl;
					cout<<i<<endl;
					return 0; 
				} else {
					r[j]-=di;
				}
			}
		}
		l=mid+1;
	}
	cout<<0<<endl;
	return 0;
} 
