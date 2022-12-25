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
	int n, k; cin >> n >> k;
	vector<int> segment(n << 1);
	
	for (int i = n; i < (n << 1); ++i) 
		cin >> segment[i];

	for (int i = n - 1; i > 0; --i)
		segment[i] = __gcd(segment[i << 1], segment[i << 1 ^ 1]);

	int res = 0;

	for (int i = 0; i + k <= n; ++i) {
		int gcd = segment[i + n];
		for (int left = i + n, right = i + k + n; left < right; left >>= 1, right >>= 1) {
			if (left & 1) gcd = __gcd(segment[left++], gcd);
			if (right & 1) gcd = __gcd(segment[--right], gcd);
		}
		res = max(res, gcd);
	}

	cout << res << '\n';
}

int main() {
	fastio();
	int t = 1; // cin >> t;
	while(t--) solve();
	return 0;
}