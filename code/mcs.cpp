#include <cstdio>
#include <queue>
using namespace std;

const int dx1[] = { -2, -1, 1, 2, 2, 1, -1, -2 },
		  dy1[] = { -1, -2, -2, -1, 1, 2, 2, 1 },
		  dx2[] = { 0, 2, 0, -2 },
		  dy2[] = { 2, 0, -2, 0 };
struct node {
	int x, y, s;
	node(int _x = 0, int _y = 0, int _s = 0) {
		x = _x, y = _y, s = _s;
	}
};
queue<node> q;
int r, c, sx, sy, fx, fy, ans = 0x7fffffff;
bool map1[51][51], map2[51][51];

int main() {
	freopen("mcs.in", "r", stdin);
	freopen("mcs.out", "w", stdout);
	scanf("%d%d", &r, &c);
	scanf("%d%d", &sx, &sy);
	scanf("%d%d", &fx, &fy);
	map1[sx][sy] = true;
	q.push(node(sx, sy, 1));
	while(!q.empty()) {
		node tmp = q.front();
		if(tmp.x == fx && tmp.y == fy) {
			ans = min(ans, tmp.s - 1);
			break;
		}
		if(tmp.s % 2) {
			for(int k = 0; k < 8; ++k) {
				int nx = tmp.x + dx1[k],
					ny = tmp.y + dy1[k];
					if(nx > 0 && nx <= r && ny > 0 && ny <= c && !map1[nx][ny]) {
						map1[nx][ny] = true;
						q.push(node(nx, ny, tmp.s + 1));
					}
			}
		}
		else {
			for(int k = 0; k < 4; ++k) {
				int nx = tmp.x + dx2[k],
					ny = tmp.y + dy2[k];
				if(nx > 0 && nx <= r && ny > 0 && ny <= c && !map2[nx][ny]) {
					map2[nx][ny] = true;
					q.push(node(nx, ny, tmp.s + 1));
				}
			
			}
		}
		q.pop();
	}
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
