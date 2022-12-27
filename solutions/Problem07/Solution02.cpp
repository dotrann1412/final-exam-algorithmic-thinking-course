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

#ifndef __STRING_UTILS__
#define __STRING_UTILS__

std::vector<std::string> tokens(const std::string& s) {
	std::stringstream ss(s);
	std::vector<std::string> ls;
	for (std::string tmp; ss >> tmp; ls.push_back(tmp));
	return ls;
}

std::vector<std::string> split(const std::string& string, const std::string& separator)
{
	int offset = 0;
	std::vector<std::string> result;

	for (int index = string.find(separator, offset); index != std::string::npos; index = string.find(separator, offset))
	{
		result.push_back(string.substr(offset, index - offset));
		offset = index + separator.size();
	}

	result.push_back(string.substr(offset));
	return result;
}

#endif // __STRING_UTILS__

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
	string buffer; cin >> buffer;
	vector<string> tokenizedBuffer = split(buffer, ",");
	vector<int> a(tokenizedBuffer.size());

	for (int i = 0; i < a.size(); ++i) {
		a[i] = std::stoi(tokenizedBuffer[i]);
	}

	int n = a.size();
	vector<int> maxPref(n);
	vector<int> maxSuff(n);
	maxPref[0] = a[0], maxSuff[n - 1] = a[n - 1];
	for (int i = 1; i < n; ++i)
		maxPref[i] = max(a[i], maxPref[i - 1]);
	
	for (int i = n - 2; i >= 0; --i)
		maxSuff[i] = max(a[i], maxSuff[i + 1]);

	int res = 0;
	for (int i = 1; i < n - 1; ++i) {
		res += min(maxSuff[i], maxPref[i]) - a[i];
		cerr << min(maxSuff[i], maxPref[i]) - a[i] << '\n';
	}

	cout << res << '\n';
}

int main() {
	fastio();
	int t = 1; // cin >> t;
	while(t--) solve();
	return 0;
}