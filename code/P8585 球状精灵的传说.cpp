#include<bits/stdc++.h>
using namespace std;
int n,cnt=1;
int max_old_x=INT_MIN,maxi_old,maxi_new,maxj_new,max_new_x=INT_MIN;
struct node{
	int x,y,z,point,i,j;
}elf_old[500005],elf_new[1500005];
int point(int a){
	return a*a*a>>2;
}
void cmp(node &a){
	if(a.x>a.y) swap(a.x,a.y);
	if(a.x>a.z) swap(a.x,a.z);
	if(a.y>a.z) swap(a.y,a.z);
}
void add(int a,int b,int c,int i,int j){
	if(a>b) swap(a,b);
	if(a>c) swap(a,c);
	elf_new[cnt].x=a;
	elf_new[cnt].y=b;
	elf_new[cnt].z=c;
	elf_new[cnt].i=i;
	elf_new[cnt].j=j;
	cnt++;
}
void make_both(node a,node b){
	if(a.y!=b.y||a.z!=b.z) return;
	if(a.x+b.x>a.y){
		add(a.x+b.x,a.y,a.z,a.i,b.i);
	}
	return;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&elf_old[i].x,&elf_old[i].y,&elf_old[i].z);
		cmp(elf_old[i]);
		elf_old[i].i=i;
		if(elf_old[i].x>max_old_x){
			max_old_x=elf_old[i].x;
			maxi_old=i;
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			make_both(elf_old[i],elf_old[j]);
		}
	}
	for(int i=1;i<=cnt;i++){
		if(elf_new[i].x>max_new_x){
			max_new_x=elf_new[i].x;
			maxi_new=elf_new[i].i;
			maxj_new=elf_new[i].j;
		}
	}
	if(max_old_x>max_new_x){
		cout<<0<<endl;
		cout<<maxi_old<<endl;
		cout<<point(max_old_x)<<endl;
	} else {
		cout<<1<<endl;
		cout<<maxi_new<<" "<<maxj_new<<endl;
		cout<<point(max_new_x)<<endl;
	}
	return 0;
} 
