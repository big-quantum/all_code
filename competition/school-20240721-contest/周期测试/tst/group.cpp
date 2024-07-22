#include<bits/stdc++.h>
#define ll long long

using namespace std;

int Find(vector<int>& parent, int index) {
    if (parent[index] != index) {
        parent[index] = Find(parent, parent[index]);
    }
    return parent[index];
}

void Union(vector<int>& parent, int index1, int index2) {
    parent[Find(parent, index1)] = Find(parent, index2);
}

int findCircleNum(vector<vector<int>> isConnected) {
    int cities = isConnected.size();
    vector<int> parent(cities);
    for (int i = 0; i < cities; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < cities; i++) {
        for (int j = i + 1; j < cities; j++) {
            if (isConnected[i][j] == 1) {
                Union(parent, i, j);
            }
        }
    }
    int provinces = 0;
    for (int i = 0; i < cities; i++) {
        if (parent[i] == i) {
            provinces++;
        }
    }
    return provinces;
}

int main() {
    freopen("group.in", "r", stdin);
    freopen("group.out", "w", stdout);

    int n;
    cin >> n;
    vector<vector<int>> isConnected(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }

    cout << findCircleNum(isConnected) << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
