/**
 * 目标是考虑所有可能的方案，每种方案的员工数量不超过n，利润至少为minProfit。
 * 为了实现这一点，定义状态转移方程dp[i][j][k]，其中：
 *   i 代表考虑到的前 i 个工作。
 *   j 代表使用了 j 个员工。
 *   k 代表获得的利润。
 * 初始化 dp[0][0][0] = 1 ，表示没有工作、没有员工和没有利润的情况只有一种。
 * 状态转移方程为：
 *   1. 不选择第i个工作：dp[i][j][k] += dp[i-1][j][k]
 *   2. 选择第i个工作（前提是有足够的员工）：dp[i][j][k] += dp[i-1][j-group[i]][max(0, k-profit[i])]
 */
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e9 + 7;
int n, k, minprofit;
int profit[105], group[105];
int dp[105][105][105];

int main() {
    cin >> n >> k >> minprofit;
    for(int i = 1; i <= k; i++) {
        cin >> group[i] >> profit[i];
    }

    dp[0][0][0] = 1;
    for(int i = 1; i <= k; i++) {
        for(int j = 0; j <= n; j++) {
            for(int p = 0; p <= minprofit; p++) {
                dp[i][j][p] = dp[i-1][j][p];
                if(j >= group[i]) {
                    dp[i][j][p] = (dp[i][j][p] + dp[i-1][j-group[i]][max(0, p-profit[i])]) % maxn;
                }
            }
        }
    }

    int ans = 0;
    for(int j = 0; j <= n; j++) {
        ans = (ans + dp[k][j][minprofit]) % maxn;
    }

    cout << ans << endl;

    return 0;
}

/**
 * 程序差异：
 * 1. 状态定义的差异：
 *  - dp[i][j]表示使用了i个员工，考虑到了前j种工作后能够获得的最大利润。
 *  - 应该用dp[i][j][k]表示考虑到了前i个工作，使用了j个员工，并且获得了k利润的方案数。
 * 这是最根本的问题，你只关注最大利润，而要求的是计算所有满足条件的盈利方案数。
 *
 * 2. 状态转移的差异：
 *  - 你想通过更新dp[i][j]为max(dp[i - 1][j], dp[i - group[j]][j - 1] + profit[j])，
 *          这意味着要么不选择第j种工作，要么选择它并添加其利润。
 *          但这种转移是错误的，因为这可能会导致多次选择同一种工作，或者在选择一项工作后再次选择之前的工作。
 *  - 应该考虑选择或不选择当前工作，并根据这个决策进行状态转移，这可以确保正确地考虑了所有可能的组合。
 *
 * 3. 计数的方式的差异：
 *  - 每当你发现某种组合的利润增加并且高于minprofit时就增加ans，但由于上述提到的状态定义和转移的问题，这种计数方法不准确。
 *  - 应该在最后统计所有使用0到n名员工并获得至少minprofit利润的方案。
 */
