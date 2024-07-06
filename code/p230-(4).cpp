#include<bits/stdc++.h>
using namespace std;
int n=1,x,ans;
char s1[205],s2[205];
int main(){
	while((s1[n]=getchar())!='\n')
		n++;
	n=1;
	while((s2[n]=getchar())!='\n')
		n++;
	n=1;
	while(s1[n]!='\n'){
		if(s1[n]==s2[n]) cout<<n<<" ";
		n++;
	}
	return 0;
} 
/*
I am a girl.I was born in 2002.
I am a giel.I was birn in 2012.
*/ 
