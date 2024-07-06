#include<bits/stdc++.h>
using namespace std;
int n,id,num[100005];
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&id);
		num[id] = i;
	}
	for(int i = 1;i < n;i++)
		printf("%d ",num[i]);
	printf("%d\n",num[n]);
	return 0;
} 

               
         


