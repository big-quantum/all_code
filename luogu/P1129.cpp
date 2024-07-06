#include<bits/stdc++.h>
using namespace std;

int n, cnt, t;
int mapp[205][205], right_match[205];
bool vis_right[205];

bool match(int left){
    for(int right = 1; right <= n; right++){
        if(mapp[left][right] && !vis_right[right]){
            vis_right[right] = true;
            if(right_match[right] == 0 || match(right_match[right])){
                right_match[right] = left;
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin >> t;
    while(t--){
        memset(right_match, 0, sizeof(right_match));
        cnt = 0;

        cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> mapp[i][j];
            }
        }

        for(int i = 1; i <= n; i++){
            memset(vis_right, false, sizeof(vis_right));
            if(match(i)) cnt++;
        }
        
        if(cnt == n) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}