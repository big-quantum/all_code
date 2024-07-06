#include<bits/stdc++.h>
using namespace std;
int n,m,dp[35][35];
int main(){
	cin>>n>>m;
	dp[0][1]=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(j==1) dp[i][j]=dp[i-1][n]+dp[i-1][j+1];
			else if(j==n) dp[i][j]=dp[i-1][j-1]+dp[i-1][1];
			else dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
		}
	}
	cout<<dp[m][1]<<endl;
	return 0;
}
//https://www.luogu.com.cn/problem/P1057
/*GPT回答 
算法1：暴力枚举

对于每一个方格，判断它是否能够积水，可以枚举它向左和向右能够延伸到的最高高度，取两者的较小值，减去方格自身的高度即为该方格能够积水的量。最后将所有方格的积水量相加即可得到总积水量。

时间复杂度

对于每一个方格，需要枚举它向左和向右的高度，复杂度为 O(n^2)O(n 
2
 )，总时间复杂度为 O(n^3)O(n 
3
 )。

空间复杂度

只需要常数空间，空间复杂度为 O(1)O(1)。

算法2：动态规划

对于一个方格，如果它能够积水，那么它左侧和右侧必须有比它高度高的瓦片。所以我们可以预处理出每个方格向左和向右能够延伸到的最高高度，然后对于每个方格，如果它左侧和右侧的最高高度都大于它自身的高度，那么它就能够积水，积水量为左侧和右侧最高高度的较小值减去方格自身的高度。

时间复杂度

预处理出每个方格向左和向右能够延伸到的最高高度复杂度为 O(n)O(n)，遍历每个方格再计算它是否能够积水的复杂度也为 O(n)O(n)，总时间复杂度为 O(n)O(n)。

空间复杂度

需要 O(n)O(n) 的额外空间来存储每个方格向左和向右能够延伸到的最高高度，空间复杂度为 O(n)O(n)。

C++ 代码

算法1：

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int lmax = 0, rmax = 0;
            for (int j = i; j >= 0; j--) {
                lmax = max(lmax, height[j]);
            }
            for (int j = i; j < n; j++) {
                rmax = max(rmax, height[j]);
            }
            ans += min(lmax, rmax) - height[i];
        }
        return ans;
    }
};

算法2：

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n), rightMax(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            leftMax[i] = i == 0 ? height[i] : max(leftMax[i - 1], height[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            rightMax[i] = i == n - 1 ? height[i] : max(rightMax[i + 1], height[i]);
        }
        for (int i = 0; i < n; i++) {
            if (leftMax[i] > height[i] && rightMax[i] > height[i]) {
                ans += min(leftMax[i], rightMax[i]) - height[i];
            }
        }
        return ans;
    }
};
*/
