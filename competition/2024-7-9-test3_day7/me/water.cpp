#include<bits/stdc++.h>
using namespace std;
/*
对于中间的树，它的左右两侧的树的高度一定是一个下降序列
这棵树不能在左右端点,~~选择中间最高的树,如果有同样高的树，~~(枚举)这棵树要增高的高度是左侧/右侧离它最远的最高的树的高度和它的高度的差+ 1 + 距离
对于左右两侧的数，从两端向中间枚举，保证上升即可
*/

int n, h[200005], maxh = INT_MAX, hup[200005], pos, cnt;
vector<int> x;

pair<int, pair<int, int>> check(){
    int len = 0, minn = INT_MAX, x = 0, y = 0;
    for(int i = 1; i <= n; i++){
        if(hup[i] > 0) {
            int xx, yy;
            xx = i;
            //cout << i << endl;
            while(hup[i] > 0){
                //cout << hup[i] << " "  << i << endl;
                minn = min(hup[i], minn);
                i++;
            }
            yy = i - 1;
            if(!len){
                len = yy - xx + 1;
                x = xx;
                y = yy;
            } else {
                if(len < yy - xx + 1){
                    len = yy - xx + 1;
                    x = xx;
                    y = yy;
                }
            }
        }
    }
    return make_pair(minn, make_pair(x, y));
}

int main(){
    freopen("water.in", "r", stdin);
    freopen("water.out", "w", stdout);
    cin >> n;
    //cin >> h[1];
    for (int i = 1; i <= n; i++){
        cin >> h[i];
        // if(h[i] >= maxh){
        //     if(h[i] == maxh) x.push_back(i);
        //     else {
        //         while (!x.empty()){
        //             x.pop_back();
        //         }
        //         x.push_back(i);
        //         maxh = max(h[i], maxh);
        //     }
        // }
    }
    for(int i = 2; i < n; i++){
        int maxhh = INT_MIN, high;
        for(int j = i - 1; j >= 1; j--){
            if(h[i] < h[j]) high = h[j] - h[i] + i - j;
            else high = 0;
            //cout << high << endl;
            maxhh = max(maxhh, high);
        }
        for(int j = i + 1; j <= n; j++){
            if(h[i] < h[j]) high = h[j] - h[i] + j - i;
            else high = 0;
            //cout << high << endl;
            maxhh = max(maxhh, high);
        }
        //cout << maxhh << endl;
        if(maxh > maxhh){
            maxh = maxhh;
            pos = i;
        }
    }
    hup[pos] = maxh;
    //cout << pos << endl;
    cnt += hup[pos];
    //cout << pos << endl;


    stack<int> stk;
    stk.push(h[1]);
    for(int i = 2; i <= pos - 1; i++){
        if(stk.top() < h[i]){
            stk.push(h[i]);
        } else {
            hup[i] = stk.top() - h[i] + 1;
            cnt += hup[i];
            stk.push(stk.top() + 1);
        }
    }
    while(!stk.empty()){
        stk.pop();
    }
    stk.push(h[n]);
    for(int i = n - 1; i >= pos + 1; i--){
        if(stk.top() < h[i]){
            stk.push(h[i]);
        } else {
            hup[i] = stk.top() - h[i] + 1;
            cnt += hup[i];
            stk.push(stk.top() + 1);
        }
    }
    //no
    //  for(int i = 1; i <= n; i++){
    //         cout << hup[i] << " ";
    //     }
    //     cout << endl;
    int cntt = 0;
    for(int i = 1; i <= cnt; i++){
        pair<int, pair<int, int>> tmp = check();
        //cout << tmp.first << " " << tmp.second.first << " " << tmp.second.second << endl;
        if(tmp.first == INT_MAX) break;
        for(int j = tmp.second.first; j <= tmp.second.second; j++){
            hup[j] -= tmp.first;
        }
        cntt+=tmp.first;
    }
    cout << cntt << endl;
    return 0;
}
