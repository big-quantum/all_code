#include<bits/stdc++.h>
using namespace std;
int num[26],len;
char st[100];
int main(){
	while((st[len]=getchar())!='\n')
		len++;
	for(int i=0;i<len;i++)
		++num[st[i]-'a'];
	for(int i=0;i<len;i++)
		if(num[st[i]-'a']==1)
			putchar(st[i]);
	return 0;
} 
