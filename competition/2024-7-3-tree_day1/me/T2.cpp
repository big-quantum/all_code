#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10005;

int n, q;
int from_s[MAXN], next_s[MAXN], to_s[MAXN], cnt;
long long w[MAXN];
bool flag1 = true, flag2 = true;//flag1 ��״ͼ, flag2 �ջ�ͼ

void add(int u, int v){
    from_s[++cnt] = next_s[u];
    to_s[cnt] = v;
    next_s[cnt] = cnt;
}


/* 
vector<int> road;
bool vis[MAXN];
void find_road(int from, int to){
    
    //road.push_back(from);
    for(int i = from_s[from]; i != 0; i = next_s[i]){
        if(to_s[i] == to){
            road.push_back(to_s[i]);
            
            return ;
        } else {
            road.push_back(to_s[i]);
            lazy_road(to_s[i], to);

        }
    }
}
*/
int main(){
    freopen("T2.in", "r", stdin);
    freopen("T2.out", "w", stdout);
    cin >> n;
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    if(tmp1 < tmp2) swap(tmp1, tmp2);
    add(tmp1, tmp2);
    //add(tmp2, tmp1);
    for(int i = 2; i < n; i++){
        int f, t;
        cin >> f >> t;
        if(f < t) swap(f, t);
        add(f, t);
        //add(t, f);
        if(f != t + 1 || t != f + 1) flag1 = false;
        //if((tmp1 != t && tmp2 != f) || (tmp1 != f && tmp2 != t)) flag2 = false;
    }
    cin >> q;
    for(int i = 1; i <= q; i++){
        int s, t, k;
        cin >> s >> t >> k;
        if(s < t) swap(s, t);
        w[s] += k;
        if(flag1){
            int tmp = to_s[from_s[s]];
            while(t != tmp){
                w[tmp] += k;
                tmp = to_s[from_s[tmp]];
            }
        }
        w[t] += k;
        //lazy_road(s, t, k);
    }
    for(int i = 1; i <= n; i++){
        cout << w[i] << endl;
    }
    return 0;
}

