#include<bits/stdc++.h>
using namespace std;

int n, t;

int main(){
    cin >> t;
    while(t--){
        stack<string> stk;
        cin >> n;
        for(int i = 1; i <= n; i++){
            string s;
            cin >> s;
            if(s == "push"){
                string tmp;
                cin >> tmp;
                stk.push(tmp);
            }
            if(s == "pop"){
                if(stk.empty()) cout << "Empty" << endl;
                else stk.pop();
            }
            if(s == "query"){
                if(stk.empty()) cout << "Anguei!" << endl;
                else cout << stk.top() << endl;
            }
            if(s == "size"){
                cout << stk.size() << endl;
            }
        }
    }

    return 0;
}