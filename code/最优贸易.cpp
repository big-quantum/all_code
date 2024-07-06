#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,z;
int v[100005],t[100005],val[100005];//第v[i]点为从1到i一路上最小值 t[i]表示从i到中的最大值 val[i]表示第i座城市中水晶球的价格 
vector<int>gra[100005],graf[100005];//gra正图 graf反图 
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
    	scanf("%d%d%d",&x,&y,&z);
    	gra[x].push_back(y);
    	graf[y].push_back(x);
		if(z==2) {
			gra[y].push_back(x);
    		graf[x].push_back(y);
		}
	}
    return 0;
}
