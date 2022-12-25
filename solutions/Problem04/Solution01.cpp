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

template <class T> 
std::istream &operator >> (std::istream &s, std::vector<T> &a) {
	for(T &x: a) s >> x;
	return s;
}

template <class T> 
std::ostream &operator << (std::ostream &s, const std::vector<T> &a) {
	for(const T &x: a) s << x << ' ';
	return s;
}

void solve() {
	int n; cin >> n;
	vector<int> a(n); cin >> a;
	
	set<int> tmp;
	for (auto x: a) 
		tmp.insert(x);

	unordered_map<int, int> indexes;
	for (auto x: tmp)
		indexes[x] = indexes.size();

	int segmentSize = indexes.size();
	vector<int> seg(segmentSize << 1, 0);

	int res = 0;

	for (int i = 0; i < n; ++i) {
		for (int left = indexes[a[i]] + segmentSize, right = segmentSize << 1;
			left < right; left >>= 1, right >>= 1) {
			if (left & 1) res += seg[left++];
			if (right & 1) res += seg[--right];
		}

		int idx = indexes[a[i]] + segmentSize - 1;
		
		for (++seg[idx]; 
			idx; idx >>= 1) {
			seg[idx >> 1] = seg[idx] + seg[idx ^ 1];
		}
	}

	cout << res << '\n';
}

int main() {
	fastio();
	int t = 1; // cin >> t;
	while(t--) solve();
	return 0;
}