#include<bits/stdc++.h>
using namespace std;
int num[26],len,i;
char st[100];
int main(){
	while((st[len]=getchar())!='\n')
		len++;
	while(st[i]!='.'){
		putchar(st[i]);
		i++;
	}
	if(st[i+6]>='5') st[i+5]++;
	for(int j=1;j<=6;j++)
		cout<<st[j+i-1];
	return 0;
} 
