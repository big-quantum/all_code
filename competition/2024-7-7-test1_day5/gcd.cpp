#include<bits/stdc++.h>
using namespace std;


int n, a[300005], gcdd;
vector<pair<int, int>> f[3005];

vector<int> prime;
bool is_prime[1000005];
void _init(){
    memset(is_prime, true, sizeof(is_prime));
    prime.push_back(2);
    for(int j = 2; j <= 5005; j++){
        if(is_prime[j]){
            prime.push_back(j);
            for(auto i : prime){
                if(i * j <= 1000000) is_prime[i * j] = false;
                else break;
            }
        }
    }
}

void break_prime(int a){
    while (a > 1){
        for(auto i : prime){
            int cntnum = 0;
            bool flag = false;
            for(;a % i == 0;) {
                flag = true;
                cntnum++;
                a /= i;
            }
            if(flag) f[i].push_back(make_pair(i, cntnum));
        }
    }
    return;
}

int gcd(int a, int b){
    if(b != 0){
        return gcd(b, a % b);
    } else {
        return a;
    }
}

bool vis[3005], flag;
bool check(int m){
    if(m == 0){
        int max_gcd = -1;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                if(max_gcd == -1){
                    max_gcd = a[i];
                    continue;
                } else {
                    max_gcd = gcd(max_gcd, a[i]);
                }
            }
        }
        if(max_gcd > gcdd){
            flag = true;
            return true;
        }
        return false;
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i] && !flag){
            vis[i] = true;
            check(m - 1);
            vis[i] = false;
        }
    }
    if(flag) return true;
    else return false;
}

int main(){
    freopen("gcd.in", "r", stdin);
    freopen("gcd.out", "w", stdout);
    cin >> n;
    _init();
    cin >> a[1];
    gcdd = a[1];
    break_prime(a[1]);
    for(int i = 2; i <= n; i++){
        cin >> a[i];
        gcdd = gcd(a[i], gcdd);
        break_prime(a[i]);
    }
    int left = 1, right = n, mid, midd;
    while(left <= right){
        mid = (left + right) / 2;
        if(midd == mid) break;
        else midd = mid;
        if(check(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << mid << endl;
    //cout << -1 << endl;
    return 0;
}