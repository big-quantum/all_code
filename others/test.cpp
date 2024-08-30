class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        long long n = board.size(), m = board[0].size(), ans = INT_MIN;
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                q.push_back(make_pair(board[i][j], make_pair(i, j)));
            }
        }
        while(!q.empty()){
            pair<int, pair<int, int>> tmp = q.top();
        }
        return ans;
    }
};