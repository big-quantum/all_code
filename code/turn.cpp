#include<bits/stdc++.h>
using namespace std;
int n,ya[110][110],yb[110][110];
string s;
void read(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>ya[i][j];
		} 
	}
	cin>>s;
} 
void fz(char c,int a[110][110],int b[110][110]){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			switch(c){
				case'A':b[j][n+1-i]=a[i][j];break; 
				case'B':b[n+1-j][i]=a[i][j];break; 
				case'C':b[j][n+1-j]=a[i][j];break; 
				case'D':b[n+1-j][j]=a[i][j];break; 
			}
		}
	}
}
void copy(int a[][110],int b[][110]){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=b[i][j];
		}
	}
}
int main(){
	read();
	for(int i=0;i<s.length();i++){
		fz(s[i],ya,yb);
		copy(ya,yb);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<ya[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
