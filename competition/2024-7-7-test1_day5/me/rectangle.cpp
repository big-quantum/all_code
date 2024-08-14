#include<bits/stdc++.h>
using namespace std;

int n, x[2005], y[2005];
long long ans;
vector<int> px[2005], py[2005];
map<pair<int, int>, bool> point;

int main(){
    freopen("rectangle.in", "r", stdin);
    freopen("rectangle.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
        point[make_pair(x[i], y[i])] = true;
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + 1 ; j <= n; j++){
            if(x[i] - x[j] == 0){
                py[i].push_back(y[j]);
                //cout << x[i] << " " << y[i] << " " << x[j] << " " << y[j] << endl;
            }
            if(y[i] - y[j] == 0){
                px[i].push_back(x[j]);
                //cout << x[i] << " " << y[i] << " " << x[j] << " " << y[j] << endl;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(auto j : px[i]) {
            for(auto k : py[i]){
                if(point[make_pair(j, k)]){
                    //cout << x[i] << " " << y[i] << " " << j << " " << k << endl;
                    ans++;
                }
            }
        } 
    }
    cout << ans << endl;
    return 0;
}