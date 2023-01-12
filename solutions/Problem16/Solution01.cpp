#include <bits/stdc++.h>

using namespace std;

#define init(file_name) freopen(filename.in, "r", stdin); freopen(filename.out, "w", stdout)
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(a) a.begin(), a.end()

#define ll long long
#define vt vector
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define db double

const ll MaxN = 1e5 + 5;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const db eps = 1e-5;
const db pi = acos(-1);

void solve() {
	int n; cin >> n;
	vector<vector<int>> g(n, vector<int>());
	for (int i = 0, x, y; i < n - 1; ++i) {
		cin >> x >> y, --x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		queue<pii> que;
		que.push({i, 0});
		vector<bool> mark(n, false);
		mark[i] = true;
		while (!que.empty()) {
			int cur = que.front().fi;
			int cost = que.front().se;
			que.pop();
			for (int adj: g[cur]) {
				if (!mark[adj]) {
					mark[adj] = true;
					ans += cost + 1;
					// cout << i + 1 << ' ' << adj + 1 << ' ' << cost + 1 << '\n';
					que.push({adj, cost + 1});
				}
			}
		}
	}

	cout << ans / 2 << '\n';
}

int main() {
	fastio();
	int t = 1; // cin >> t;
	while(t--) solve();
	return 0;
}