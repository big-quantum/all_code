#include <bits/stdc++.h>
using namespace std;
int main() {
int a,b=0,i,sum=0,j;
cin>>a;
for(i=1; i>=1; i++) {
for(j=1; j<=i; j++) {
b=b+1;
sum=sum+i;
if(b>=a)
break;
}
if(b>=a)
break;
}
cout<<sum;
return 0;
}
