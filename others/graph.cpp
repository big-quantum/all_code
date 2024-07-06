#include<bits/stdc++.h>
using namespace std;
const int MAXN1 = 100005;
const int MAXN2 = 505;
int n, m;

//save_graph

//save_graph_1
struct node{
    int next, to, w, from;
}edge1[MAXN1];
int head[MAXN1], cnt;

void add_edge1(int from, int to, int w){
    edge1[++cnt].w = w;
    edge1[cnt].to = to;
    edge1[cnt].from = from;
    edge1[cnt].next = head[from];
    head[from] = cnt;
}
//save_graph_1_end

//save_graph_2
struct edge{
    int to, w;
};
vector<edge> edge2[MAXN1];

void add_edge2(int from, int to, int w){
    edge2[from].push_back({to, w});
}
//save_graph_2_end

//save_graph_3 
int edge3[MAXN2][MAXN2];

void add_edge3(int from, int to, int w){
    edge3[from][to] = w;
}
//save_graph_3_end

// save_graph_end

//floyd
int dis_floyd[405][405];

void floyd(int n){//多源最短路
    memset(dis_floyd, 0x3f, sizeof(dis_floyd));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                dis_floyd[j][k] = min(dis_floyd[j][k], dis_floyd[j][i] + dis_floyd[i][k]);
            }
        }
    }
}
//floyd_end

//bellman_ford
int dis_bellman_ford[405];

void bellman_ford_save1(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= cnt; j++){
            dis_bellman_ford[edge1[j].to] = min(edge1[j].to, edge1[j].from + edge1[j].w);
        }
    }
}

void bellman_ford_save3(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dis_bellman_ford[i] = min(dis_bellman_ford[i], dis_bellman_ford[j] + edge3[i][j]);
        }
    }
}
//bellman_ford_end

//spfa
vector<int> dis(MAXN1, INT_MAX);//赋初值
bool inqueue[MAXN1];

void spfa_save1(int u){
    queue<int> q;
    q.push(u);
    dis[u] = 0;
    inqueue[u] = true;
    while (!q.empty()){
        int f = q.front();
        q.pop();
        inqueue[f] = false;
        for (int i = head[f]; i != 0; i = edge1[i].next){
            int to = edge1[i].to, w = edge1[i].w;
            if(dis[to] > dis[f] + w){
                dis[to] = dis[f] + w;
                if(!inqueue[f]){
                    inqueue[f] = true;
                    q.push(f);
                }
            }
        }
    }
}

void spfa_save_2(int u){
    queue<int> q;
    q.push(u);
    dis[u] = 0;
    inqueue[u] = true;
    while (!q.empty()){
        int f = q.front();
        q.pop();
        inqueue[f] = false;
        for (int i = 1; i <= edge2[f].size(); i++){
            
        }
        
    }
    
}

//spfa_end


//tarjan
void tarjan(int u){

}
//tarjan_end

int main(){


    return 0;
}