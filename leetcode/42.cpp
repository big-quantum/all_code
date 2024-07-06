#include<bits/stdc++.h>
using namespace std;

int n, length[100005], ans;
stack<int> sta;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> length[i];
    }
    for(int i = 1; i <= n; i++){
        while(!sta.empty() && length[i] > length[sta.top()]){
            int top = sta.top();
            sta.pop();
            if(sta.empty()){
                break;
            }
            int left = sta.top();
            ans += (i - left - 1) * (min(length[i], length[left]) - length[top]);
        }
        sta.push(i);
    }
    cout << ans << endl;
    return 0;
    /*
    #include<bits/stdc++.h>
    using namespace std;

    int roof[1005], n, ans;
    int stk[1005], top;

    int main(){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> roof[i];
        }

        for(int i = 1; i <= n; i++){
            while(top >= 0 && roof[i] > roof[stk[top]]){
                int mid = stk[top];
                top--;
                if (top == 0) {
                    break;
                }
                int wid = i - stk[top] - 1;
                int hei = min(roof[i], roof[stk[top]]) - roof[mid];
                ans += wid * hei;
            }
            stk[++top] = i;
        }

        cout << ans << endl;
        return 0;
    }
    */
}