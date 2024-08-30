#include<bits/stdc++.h>
using namespace std;

int n, x, num[100005], t;

int main(){
    cin >> t;
    while(t--){
        bool flag = false;
        cin >> n >> x;
        for(int i = 1; i <= n; i++){
            cin >> num[i];
        }
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if(num[i] != num[j]) flag = true;
            }
        }
        for(int i = 1; i <= n; i++){
            if(x / num[i] > 0) flag = true;
            if(x % num[i] != 0)flag = true;
        }
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    

    return 0;
}