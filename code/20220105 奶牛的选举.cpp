#include<bits/stdc++.h>
using namespace std;
int n,k;
struct node{
	int a,b,num;
}AB[50005];
bool cmp1(node a,node b){
	if(a.a>b.a) return true;
	else return false;
}
bool cmp2(node a,node b){
	if(a.b>b.b) return true;
	else return false;
}
int main(){
	cin>>n>>k; 
	for(int i=1;i<=n;i++){
		cin>>AB[i].a>>AB[i].b;
		AB[i].num=i;
	}
	sort(AB+1,AB+n+1,cmp1);
	sort(AB+1,AB+k+1,cmp2);
	cout<<AB[1].num<<endl;
	return 0;
} 	
