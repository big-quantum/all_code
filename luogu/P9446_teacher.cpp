#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MAX = 10000010;
int n, all, sum, flag;
// 每个括号序列的最小值和总和
struct csum {
    int mix = 0, sum = 0;
} summ[MAX];

// 存储每个输入的括号序列
char s[MAX];
// 存储正向和负向的序列索引
vector<int> pos, neg;

void cmin(int &a, int b) {
    a = a < b ? a : b;
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> (s + 1); // 从 s[1] 开始读取括号序列
        int len = strlen(s + 1); // 获取当前括号序列的长度
        for (int j = 1; j <= len; ++j) {
            summ[i].sum += (s[j] == '(' ? 1 : -1); // 更新当前序列的总和
            cmin(summ[i].mix, summ[i].sum); // 更新当前序列的最小值
        }

        all += summ[i].sum; // 更新所有序列的总和
        if (summ[i].sum >= 0) {
            pos.emplace_back(i); // 如果总和非负，加入正向序列
        } else {
            neg.emplace_back(i); // 如果总和负，加入负向序列
        }
    }
    // 如果所有序列的总和不为零，输出 impossible
    if (all != 0) {
        cout << "impossible" << endl;
        return 0;
    }

    // 对正向序列按照 mix 值从大到小排序
    sort(pos.begin(), pos.end(), [&](int x, int y) { return summ[x].mix > summ[y].mix; });
    // 对负向序列按照 mix-sum 值从小到大排序
    sort(neg.begin(), neg.end(), [&](int x, int y) { return summ[x].mix - summ[x].sum < summ[y].mix - summ[y].sum; });

    // 检查正向序列是否满足条件
    for (auto tab: pos) {
        flag |= (sum + summ[tab].mix < 0); // 若总和小于零，设置 flag
        sum += summ[tab].sum; // 更新总和
    }
    // 检查负向序列是否满足条件，其余同上
    for (auto tab: neg) {
        flag |= (sum + summ[tab].mix < 0);
        sum += summ[tab].sum;
    }

    if (flag) {
        cout << "impossible" << endl;
        return 0;
    }

    // 输出正向和负向序列的结果
    for (auto it: pos) {
        cout << it << endl;
    }
    for (auto it: neg) {
        cout << it << endl;
    }

    return 0;
}

