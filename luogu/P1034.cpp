#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3ffffff;

int n, x[105], y[105], k, ans = INT_MAX;

struct node{
    int min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN, max_y = INT_MIN;
    bool cnt = false;
    void add(int x, int y){
        if(!cnt){
            min_x = max_x = x;
            min_y = max_y = y;
            cnt = true;
        } else {
            min_x = min(min_x, x);
            min_y = min(min_y, y);
            max_x = max(max_x, x);
            max_y = max(max_y, y);
        }
    }
    bool inrec(int x, int y){
        return x <= max_x && x >= min_x && y <= max_y && y >= min_y;
    }
    bool check(node other){
        return inrec(other.max_x, other.max_y) || inrec(other.max_x, other.min_y) || inrec(other.min_x, other.max_y) || inrec(other.min_x, other.min_y) || other.inrec(max_x, max_y) || other.inrec(max_x, min_y) || other.inrec(min_x, max_y) || other.inrec(min_x, min_y);
    }
    int area(){
        if(!cnt) return 0;
        return (max_x - min_x) * (max_y - min_y);
    }
} rec[5];

bool checkr(){
    for(int i = 1; i <= k; i++){
        for(int j = i + 1; j <= k; j++){
            if(rec[i].check(rec[j])) return false;
        }
    }
    return true;
}

void dfs(int p, int sum){
    if(sum >= ans) return;
    if(p == n){
        if(checkr()) ans = min(ans, sum);
        return;
    }
    for(int i = 1; i <= k; i++){
        node tmp = rec[i];
        rec[i].add(x[p], y[p]);
        dfs(p + 1, sum + rec[i].area() - tmp.area());
        rec[i] = tmp;
    }
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}