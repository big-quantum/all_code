#include<bits/stdc++.h>
using namespace std;
int main(){
int x,y;
cin>>x>>y;
char a;cin>>a;
if(a=='+'){
cout<<x+y;
return 0;
}
if(a=='*'){
cout<<x*y;
return 0;
}
if(a=='/'&&y!=0){
cout<<x/y;
return 0;
}
if(a=='-'){
cout<<x-y;
return 0;
}
if(a=='/'&&y==0){
cout<<"Divided by zero!";
return 0;
}
cout<<"Invalid operator!";
}
