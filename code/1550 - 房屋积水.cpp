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
/*GPT�ش� 
�㷨1������ö��

����ÿһ�������ж����Ƿ��ܹ���ˮ������ö��������������ܹ����쵽����߸߶ȣ�ȡ���ߵĽ�Сֵ����ȥ��������ĸ߶ȼ�Ϊ�÷����ܹ���ˮ������������з���Ļ�ˮ����Ӽ��ɵõ��ܻ�ˮ����

ʱ�临�Ӷ�

����ÿһ��������Ҫö������������ҵĸ߶ȣ����Ӷ�Ϊ O(n^2)O(n 
2
 )����ʱ�临�Ӷ�Ϊ O(n^3)O(n 
3
 )��

�ռ临�Ӷ�

ֻ��Ҫ�����ռ䣬�ռ临�Ӷ�Ϊ O(1)O(1)��

�㷨2����̬�滮

����һ������������ܹ���ˮ����ô�������Ҳ�����б����߶ȸߵ���Ƭ���������ǿ���Ԥ�����ÿ����������������ܹ����쵽����߸߶ȣ�Ȼ�����ÿ����������������Ҳ����߸߶ȶ�����������ĸ߶ȣ���ô�����ܹ���ˮ����ˮ��Ϊ�����Ҳ���߸߶ȵĽ�Сֵ��ȥ��������ĸ߶ȡ�

ʱ�临�Ӷ�

Ԥ�����ÿ����������������ܹ����쵽����߸߶ȸ��Ӷ�Ϊ O(n)O(n)������ÿ�������ټ������Ƿ��ܹ���ˮ�ĸ��Ӷ�ҲΪ O(n)O(n)����ʱ�临�Ӷ�Ϊ O(n)O(n)��

�ռ临�Ӷ�

��Ҫ O(n)O(n) �Ķ���ռ����洢ÿ����������������ܹ����쵽����߸߶ȣ��ռ临�Ӷ�Ϊ O(n)O(n)��

C++ ����

�㷨1��

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

�㷨2��

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
