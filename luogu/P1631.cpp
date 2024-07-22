#include<bits/stdc++.h>
using namespace std;

int n, a[100005], b[100005];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    for(int j = 1; j <= n; j++){
        q.push(make_pair(b[1] + a[j], make_pair(1, j)));
    }
    for(int i = 1; i <= n; i++){
        cout << q.top().first << " ";
        pair<int, int> k = q.top().second;
        k.first += 1;
        q.pop();
        q.push(make_pair(b[k.first] + a[k.second], k));
    }
    return 0;
}