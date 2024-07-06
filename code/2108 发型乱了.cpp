#include<bits/stdc++.h>
using namespace std;
stack <int> st;
long long ans;
int n,a[80005];
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
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]>a[j]) ans++;
			else break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
