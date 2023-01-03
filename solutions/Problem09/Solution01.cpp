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
	string s, t; cin >> s >> t;
	vector<vector<bool>> dp(s.size() + 1, vector<bool>(t.size() + 1, 0));
	int n = s.size(), m = t.size();
	dp[n][m] = true;

	auto eq = [&] (char a, char b) {
		return a == b || b == '.';
	};

	for (int i = n; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			
			bool match = (i < n) && eq(s[i], t[j]);
			
			if (1 + j < m && t[j + 1] == '*')
				dp[i][j] = dp[i][j + 2] || match && dp[i + 1][j];
			else dp[i][j] = match && dp[i + 1][j + 1];
		}
	}
	

	std::cout << (dp[0][0] ? "YES" : "NO") << std::endl;

}	

int main() {
	fastio();
	int t = 1; // cin >> t;
	while(t--) solve();
	return 0;
}