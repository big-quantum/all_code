#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,z;
int v[100005],t[100005],val[100005];//��v[i]��Ϊ��1��iһ·����Сֵ t[i]��ʾ��i���е����ֵ val[i]��ʾ��i��������ˮ����ļ۸� 
vector<int>gra[100005],graf[100005];//gra��ͼ graf��ͼ 
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
