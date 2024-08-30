#include<bits/stdc++.h>
using namespace std;

int t, n;
string a, b;

int main(){
    cin >> t;
    while(t--){
        int cnt = 0;
        cin >> n;
        cin >> a >> b;
        bool flag1 = false, flag2 = false;
        for(int i = 0; i < n; i++){
            if(a[i] == b[i]){
                flag1 = true;
            } else flag2 = true;
            if(a[i] == '1') cnt++;
        }
        if(flag2 && flag1){
            cout << "NO" << endl;
            continue;
        }
        if((cnt % 2 == 1 && flag1) || (cnt % 2 == 0 && flag2)) cnt += 3;
        cout << "YES" << endl;
        cout << cnt << endl;
        for(int i = 0; i < n; i++){
            if(a[i] == '1'){
                cout << i + 1 << " " << i + 1 << endl;
                cnt--;
            }
        }
        if(cnt != 0){
            cout << "1 1" << endl;
            cout << "2 2" << endl;
            cout << "1 2" << endl;
        }
    }


    return 0;
}