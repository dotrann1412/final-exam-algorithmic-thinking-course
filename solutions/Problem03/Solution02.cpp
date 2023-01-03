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

bool operator == (const pii& a, const pii& b) {
	return a.fi == b.fi;
}

bool operator < (const pii& a, const pii& b) {
	return a.fi < b.fi;
}

bool operator > (const pii& a, const pii& b) {
	return a.fi > b.fi;
}

bool operator <= (const pii& a, const pii& b) {
	return a.fi <= b.fi;
}

bool operator >= (const pii& a, const pii& b) {
	return a.fi >= b.fi;
}

pii operator - (const pii& a) {
	return {-a.fi, a.se};
}

void solve() {
	int n, m; cin >> n >> m;
	vector<pii> a(n), b(m);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].fi, a[i].se = i;
	}

	for (int i = 0; i < m; ++i) {
		cin >> b[i].fi, b[i].se = i;
	}

	sort(all(a)), sort(all(b));

	int res_a = 0, res_b = 0;
	for (int i = 0; i < n; ++i) {
		int k = max(0, lower_bound(all(b), -a[i]) - b.begin());
		if (abs(a[res_a].fi + b[res_b].fi) > abs(a[i].fi + b[k].fi)) {
			res_a = i, res_b = k;
		}
	}

	for (int i = 0; i < m; ++i) {
		int k = max(0, lower_bound(all(a), -b[i]) - a.begin());
		if (abs(a[res_a].fi + b[res_b].fi) > abs(b[i].fi + a[k].fi)) {
			res_a = k, res_b = i;
		}
	}


	cout << a[res_a].se + 1 << ' ' << b[res_b].se + 1 << '\n';

}

int main() {
	fastio();
	int t = 1; // cin >> t;
	while(t--) solve();
	return 0;
}