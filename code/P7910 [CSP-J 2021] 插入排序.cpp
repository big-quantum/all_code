#include<bits/stdc++.h>
using namespace std;
long long l1,l2,x,v;
long long n,q,w[8005],top[8005];
struct node{
	long long b,f;
} a[8005];
bool cmp(node a,node b){
	if(a.b<b.b) return true;
	else return false;
}
int main(){
	//freopen("sort.in","r",stdin);
	//freopen("sort.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].b);
		tmp[i].b=a[i];
		tmp[i].f=i;
	}
	stable_sort(tmp+1,tmp+1+n,cmp);
	for(int i=1;i<=n;i++){
		top[tmp[i].f]=tmp[i].b;
	}
	scanf("%lld",&l1);
	if(l1==1){
		scanf("%lld%lld",&x,&v);
		a[x]=v;
		top[x]=v;
		for(int j=x;j>1;j--){
			if(cmp(tmp[j],tmp[j-1])){
				swap(tmp[j],tmp[j-1]);
				swap(top[tmp[j].f],top[tmp[j-1].f]);
			}
		}
		for(int j=x;j<n;j++){
			if(cmp(tmp[j],tmp[j+1])){
				swap(tmp[j],tmp[j+1]);
				swap(top[tmp[j].f],top[tmp[j+1].f]);
			}
		}
	}
	if(l1==2){
		scanf("%lld",&x);
		//stable_sort(tmp+1,tmp+1+n,cmp);
		printf("%d\n",top[x]);
	}
	for(int i=2;i<=q;i++){
		scanf("%lld",&l1);
		if(l1==1){
			scanf("%lld%lld",&x,&v);
			a[x]=v;
			top[x]=v;
			for(int j=x;j>1;j--){
				if(cmp(tmp[j],tmp[j-1])){
					swap(tmp[j],tmp[j-1]);
					swap(top[tmp[j].f],top[tmp[j-1].f]);
				}
			}
			for(int j=x;j<n;j++){
				if(cmp(tmp[j],tmp[j+1])){
					swap(tmp[j],tmp[j+1]);
					swap(top[tmp[j].f],top[tmp[j+1].f]);
				}
			}
		}
		if(l1==2){
			scanf("%lld",&x);
			//stable_sort(tmp+1,tmp+1+n,cmp);
			printf("%d\n",top[x]);
		}
	}
	/*
	for(int i=2;i<=q;i++){
		scanf("%lld",&l2);
		if(l1==1&&l2==2){
			for(int j=1;j<=n;j++){
				tmp[j].b=a[j];
				tmp[j].f=j;
			}
			scanf("%lld",&x);
			stable_sort(tmp+1,tmp+1+n,cmp);
			for(int j=1;j<=n;j++){
				if(tmp[j].f==x){
					printf("%d\n",j);
					break;
				}
			}
		}
		if(l1==2&&l2==2){
			scanf("%lld",&x);
			for(int j=1;j<=n;j++){
				if(tmp[j].f==x){
					printf("%d\n",j);
					break;
				}
			}
		}
		if(l2==1){
			scanf("%lld%lld",&x,&v);
			a[x]=v;
		}
		l1=l2;
	}*/ 
	return 0;
}
