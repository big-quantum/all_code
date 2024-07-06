#include<bits/stdc++.h>
using namespace std;

int t, a, b, c;//a:2, b:1, c:0 
int two[23];
/*
思路： 首先考虑特殊数据，a = 0, b = 0;
    显然当a = 0时为链，b = 0时为完全二叉树；特判40pts
    回到正常情况，首先应考虑能否构成一棵树，由特殊情况(a = 0)推导/二叉树的特性可得 c = a + 1
    然后考虑排树：
        从有两个孩子的节点开始，优先排完全二叉树，然后排有一个孩子的节点，最后排有零个孩子的节点(数学方法)
*/
void init(){
    two[0] = 1;
    for (int i = 1; i <= 22; i++){
        two[i] = two[i - 1] * 2;
    }
}
int tot;

int main(){
    //freopen("T1.in", "r", stdin);
    //freopen("T1.out", "w", stdout);
    init();
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        if(c != a + 1){
            cout << -1 << endl;
            continue;
        }
        
        /*
        //special
        
        if(c == 0){
            cout << -1 << endl;
            continue;
        }
        if(a == 0){
            if(c != 1){
                cout << -1 << endl;
                continue;
            }
            cout << b << endl;
            continue;
        }
        if(b == 0){
            int maxdeep = 0, cnt;
            while(cnt < b){
                cnt += two[maxdeep];
                maxdeep++;
            }
            if(cnt != b) cout << -1 << endl;
            else cout << maxdeep - 1 << endl;
        }*/
        //normal
        int ans = 0, cnt = 0;
        while(a >= two[cnt]){
            a -= two[cnt];
            cnt++;
        }//cnt层
        ans += cnt;
        if(a != 0) ans++;//多出来的有两个孩子的节点
        ans += b / c;//排一个孩子的节点
        if(a != 0 && (b % c) > two[cnt + 1] - a) ans++;// 可能有一个孩子的节点可以排在右边空的地方
        if(a == 0 && b % c != 0) ans++;//有两个孩子的节点排完了，但还有有一个孩子的节点没排
        cout << ans<< endl;
    }
    return 0;
}
/*
10
2 1 3
0 0 1
0 1 1
1 0 2
1 1 3
3 1 4
8 17 9
24 36 48
1 0 0
0 3 1

ans:
2
0
1
1
-1
3
6
-1
-1
3
*/
