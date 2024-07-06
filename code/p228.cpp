#include<bits/stdc++.h>
using namespace std;
char c[27]={"Abcdefghijklmnopqrstuvwxyz"};
int main(){
	for(int i=0;i<26;++i){
		putchar(c[i]=='A'?'T':(c[i]=='T'?'A':(c[i]=='C'?'G':'C')));
		cout<<endl;	
	}
	return 0;
} 
