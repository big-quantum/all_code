#include<bits/stdc++.h>
#define ll long long

using namespace std;

int numCourses, m;
vector<vector<int>> edges;
vector<int> visited;
bool valid = true;

void init() {
    edges.clear();  // 清除全局变量的状态
    edges.resize(numCourses);
    visited.clear();
    visited.resize(numCourses, 0);
    valid = true;  // 重置valid为true
}

void dfs(int u) {
    visited[u] = 1;
    for (int v : edges[u]) {
        if (visited[v] == 0) {
            dfs(v);
            if (!valid) {
                return;
            }
        }
        else if (visited[v] == 1) {
            valid = false;
            return;
        }
    }
    visited[u] = 2;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    for (const auto& info : prerequisites) {
        edges[info[0]].push_back(info[1]); // 确保是先决条件正确的方向
    }
    for (int i = 0; i < numCourses && valid; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    return valid;
}

int main() {
    freopen("lesson.in", "r", stdin);
    freopen("lesson.out", "w", stdout);

    cin >> numCourses >> m;
    vector<vector<int>> prerequisites(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }
    init();
    if (canFinish(numCourses, prerequisites)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
