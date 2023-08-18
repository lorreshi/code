//
// Created by 石立宇 on 2023/8/11.
//

#include "../dp/sly.h"

const int maxn = 45;
const int dirs[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
char colors[maxn][maxn];
bool vis[maxn][maxn];
int n, m;
void dfs(int x, int y) {
    vis[x][y] = true;
    for (auto &[dx, dy] : dirs) {
        int nx = x + dx, ny = y + dy;
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && colors[nx][ny] == 'R') {
            dfs(nx, ny);
        }
    }
}

// 求联通分量个数
int solve() {
    memset(vis, 0, sizeof(vis));
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vis[i][j] || colors[i][j] == 'W') continue;
            dfs(i, j);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> colors[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char preColor = colors[i][j];
            colors[i][j] = 'W';
            int cnt = solve();
            printf("%d ", cnt);
            colors[i][j] = preColor;
        }
        printf("\n");
    }
    return 0;
}