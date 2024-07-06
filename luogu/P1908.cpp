#include<bits/stdc++.h>
using namespace std;

int tree[500005], n;
long long ans;
pair<int, int> num[500005];

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
}

int lowbit(int x){
    return x&(-x);
}

void change(int i, int j){
    for(int pos = i; pos <= n; pos += lowbit(pos)){
        tree[pos] += j;
    }
}

int search(int k){
    int sum = 0;
    for(int pos = k; pos > 0; pos -= lowbit(pos)){
        sum += tree[pos];
    }
    return sum;
}

int search(int i, int j){
    return search(i - 1) + search(j);
}

int main(){
    scanf("%ld", &n);
    for(int i = 1; i <= n; i++){
        scanf("%ld", &num[i].first);
        num[i].second = i;
    }
    sort(num + 1, num + n + 1, cmp);
    // for(int i = 1; i <= n; i++){
    //     num[i].second = i;
    // }
    for(int i = 1; i <= n; i++){
        change(num[i].second, 1);
        ans += i - search(num[i].second);
    }
    cout << ans << endl;
    return 0;
}