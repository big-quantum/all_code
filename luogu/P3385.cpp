#include<bits/stdc++.h>
using namespace std;

int t, n, m;

struct edge{
	int w, to, next; 
}e[30005];

int head[3005], cnt;

void add(int from, int to, int w){
	e[++cnt].w = w;
	e[cnt].to = to;
	e[cnt].next = head[from];
	head[from] = cnt;	
}

int dis[3005], cntt[3005];
bool flag[3005];

bool spfa(){
	memset(dis, 0x3f, sizeof(dis));
	memset(cntt, 0, sizeof(cntt));
	memset(flag, false, sizeof(flag));
	
	queue<int> q;
	q.push(1);
	flag[1] = true;
	dis[1] = 0;

	while(!q.empty()){
		int f = q.front();
		q.pop();
		flag[f] = false;
		for(int i = head[f]; i != -1; i = e[i].next){
			int to = e[i].to;
			if(dis[to] > dis[f] + e[i].w){
				dis[to] = dis[f] + e[i].w;
				cntt[to] = cntt[f] + 1;
				if(cntt[to] >= n) return true;
				if(!flag[to]){
					q.push(to);
					flag[to] = true;
				}
			}
		}
	}
	
	return false;

}

int main(){
	cin >> t;
	
	while(t--){
		
		memset(head, -1, sizeof(head));
		cnt = 0;

		cin >> n >> m;
		for(int i = 1; i <= m; i++){
			int u, v, w;
			scanf("%d%d%d",&u,&v,&w);
			if(w >= 0){
				add(u, v, w);
				add(v, u, w);
			} else {
				add(u, v, w);
			}
		}
		
		for(int i = 1; i <= m*2; i++){
			cout<<e[i].next<<" "<<e[i].to<<" "<<e[i].w<<endl;;
		}
		if(spfa()) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	
	return 0;
}
