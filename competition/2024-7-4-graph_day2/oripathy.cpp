#include<bits/stdc++.h>//over
using namespace std;
const int mod = 1e9 + 7;

int prime[10005], cnt;
bool is_prime[2000005];

void init(){//求素数
    memset(is_prime, true, sizeof(is_prime));
    prime[++cnt] = 2;
    for(int j = 2; j <= 1005; j++){
        if(is_prime[j]){
            prime[++cnt] = j;
            for(auto i : prime){
                is_prime[i * j] = false;
            }
        }
    }
}

int t, n, ans;
vector<int> a[100005];

int main(){
    freopen("oripathy.in", "r", stdin);
    freopen("oripathy.out", "w", stdout);
    cin >> t;
    init();
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            int tmp;
            cin >> tmp;
            if(is_prime[tmp]) a[i].push_back(tmp);
            else {
                while(tmp != 1){
                    for(int j = 1; j <= cnt; j++){
                        if(tmp % prime[j] == 0){
                            a[i].push_back(prime[j]);
                            tmp /= prime[j];
                        }
                    }
                }
            }
        }
        for (int left = 1; left <= n; left++){
            map<int, bool> if_in;
            bool flag;
            for (int right = left; right <= n; right++){
                flag = false;
                int left_num = left - 1 + n - right;
                if(left_num <= 0 || left_num >= n) continue;
                else {
                    for(int i = 1; i < left; i++){
                        for(auto j : a[i]){
                            if_in[j] = true;
                        }
                    }
                    for(int i = right + 1; i <= n; i++){
                        for(auto j : a[i]){
                            if_in[j] = true;
                        }
                    }
                    for(int i = left; i <= right; i++){
                        for(auto j : a[i]){
                            if(if_in[j] || flag) {
                                flag = true;
                                break;
                            }
                        }
                    }
                }
                if(!flag){
                    ans++;
                }
            }
        }
        cout << ans * 2 << endl;
    }
    return 0;
}