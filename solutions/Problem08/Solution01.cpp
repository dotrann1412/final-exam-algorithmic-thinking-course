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
	vector<vector<int>> res;
	int n; cin >> n;

	vector<bool> mainDiagonal(2 * n - 1, false), antiDiagonal(2 * n - 1, false);
	vector<bool> rows(n, false);

	function<void(int, vector<int>&)> magic = [&] (int col, vector<int>& pre) {
		if (col == n) {
			res.push_back(pre);
			return;
		};

		for (int row = 0; row < n; ++row) {
			int antiIdx = row + col;
			int mainIdx = (n - row - 1) + col;

			if (!mainDiagonal[mainIdx] && !antiDiagonal[antiIdx] && !rows[row]) {
				mainDiagonal[mainIdx] = antiDiagonal[antiIdx] = rows[row] = true;
				pre.push_back(row);
				magic(col + 1, pre);
				pre.pop_back();
				mainDiagonal[mainIdx] = antiDiagonal[antiIdx] = rows[row] = false;
			}
		}
	};

	vector<int> feedBuffer;
	magic(0, feedBuffer);

	cout << res.size() << '\n';
	for (auto x: res) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << (j != x[i] ? '.' : 'Q');
			}
			cout << '\n';
		}
		cout << '\n';	
	}	
}

int main() {
	fastio();
	int t = 1; // cin >> t;
	while(t--) solve();
	return 0;
}