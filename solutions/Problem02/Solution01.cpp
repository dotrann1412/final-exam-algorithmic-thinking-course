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
	const int PRIMES_RANGE = 2e3 + 1;
	vector<bool> isprime(PRIMES_RANGE, true);
	isprime[0] = isprime[1] = true;
	vector<int> primes; 
	
	for (int i = 2; i < PRIMES_RANGE; ++i) {
		if (isprime[i]) {
			for (int k = 2; i * k < PRIMES_RANGE; ++k)
				isprime[i * k] = false;
			primes.push_back(i);
		}
	}

	int res = 0;

	for (int i = 1; i <= n; ++i) {
		const int K = i << 1;
		for (auto x: primes) {
			if (x > i) break;
			res += (x + *lower_bound(all(primes), K - x) == K);
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