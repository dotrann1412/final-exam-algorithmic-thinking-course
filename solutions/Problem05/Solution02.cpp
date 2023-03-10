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
	string s, t; cin >> s >> t;
	for (auto& x: s) 	
		if (x >= 'A' && x <= 'Z') x += 32;
		
	for (auto& x: t) 
		if (x >= 'A' && x <= 'Z') x += 32;

	int64_t pows = 1;
	const int BASE = 29;
	for (int i = 0; i < t.size(); 
		(pows *= BASE) %= MOD, ++i
	);

	vector<int64_t> hashs(s.size(), s[0] - 'a');
	for (int i = 1; i < s.size(); ++i) {
		hashs[i] = (hashs[i - 1] * BASE + s[i] - 'a') % MOD;
	}

	int64_t hasht = t[0] - 'a';
	for (int i = 1; i < t.size(); ++i) {
		((hasht *= BASE) += t[i] - 'a') %= MOD;
	}

	auto get = [&] (int left, int right) {
		return (hashs[right] - (left ? hashs[left - 1] : 0) * pows + MOD * MOD) % MOD;
	};

	for (int i = 0; i + t.size() - 1 < s.size(); ++i) {
		if (hasht == get(i, i + t.size() - 1)) {
			cout << i + 1 << ' ';
		}
	}
}

int main() {
	fastio();
	int t = 1; // cin >> t;
	while(t--) solve();
	return 0;
}