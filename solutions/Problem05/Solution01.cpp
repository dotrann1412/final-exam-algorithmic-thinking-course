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

std::vector<int> kmp_table(const std::string& pattern) {
	// Preprocess the pattern to create the KMP table
	int m = pattern.size();
	std::vector<int> table(m);
	int j = 0;
	for (int i = 1; i < m; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			j++;
		}
		table[i] = j;
	}
	return table;
}

std::vector<int> kmp_search_all(const std::string& text, const std::string& pattern) {
	// Search for all instances of the pattern within the text using the KMP algorithm
	int n = text.size();
	int m = pattern.size();
	std::vector<int> table = kmp_table(pattern);
	std::vector<int> offsets;
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && text[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (text[i] == pattern[j]) {
			j++;
		}
		if (j == m) {
			// The pattern was found at index i - m + 1
			offsets.push_back(i - m + 2);
			j = table[j - 1];
		}
	}
	return offsets;
}

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
	for (auto& x: s) 
		if (x >= 'A' && x <= 'Z') x += 32;
		
	for (auto& x: t) 
		if (x >= 'A' && x <= 'Z') x += 32;

	cout << kmp_search_all(s, t) << '\n';

}	

int main() {
	fastio();
	int t = 1; // cin >> t;
	while(t--) solve();
	return 0;
}