#include<bits/stdc++.h>
using namespace std;
int n,k,x[55],y[55],ans=INT_MAX;
struct square{
	int lx,dy,rx,uy;
	bool flag;
} sq[10];
void add(int x,int y,square a){
	if(!a.flag){
		a.lx=x;
		a.rx=x;
		a.dy=y;
		a.uy=y;
		a.flag=true;
	} else {
		if(a.lx>x) a.lx=x;
		else if(a.rx<x) a.rx=x;
		if(a.dy>y) a.dy=y;
		else if(a.uy<y) a.uy=y;
	}
}
bool check_inside(int x,int y,square a){
	return a.lx<=x&&a.rx>=x&&a.dy<=y&&a.uy>=y;
}
bool check_both(square a,square b){
	if(a.flag&&b.flag){
		return check_inside(a.lx,a.dy,b)||check_inside(a.lx,a.uy,b)||check_inside(a.rx,a.dy,b)||check_inside(a.rx,a.uy,b);
	} else {
		return false;
	}
}
bool check(){
	for(int i=1;i<=k;i++){
		for(int j=i+1;j<=k;j++){
			if(check_both(sq[i],sq[j])) return false;
		}
	}
	return true;
}
int square_size(square a){
	if(a.flag) return (a.rx-a.lx)*(a.uy-a.dy);
	else return 0;
}
void dfs(int j,int area){
	if(area>=ans) return;
	if(j==n){
		if(check()&&area<ans) ans=area;
		return;
	}
	square tmp;
	for(int i=1;i<=k;i++){
		tmp=sq[i];
		add(x[j],y[j],sq[i]);
		dfs(j+1,area-square_size(tmp)+square_size(sq[i]));
		sq[i]=tmp;
	}
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}
