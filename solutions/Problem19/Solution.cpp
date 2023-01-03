#include <bits/stdc++.h>  
using namespace std;
 
const int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 3e5 + 5;

int main() {
	io
	int n, T;
	cin >> n >> T;
	vector<int> h(n+1);
	vector<ll> sum_h(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	int max_height = *max_element(h.begin(), h.end());
	// pre-process height: convert holes into pyramids
	cerr << "max height: " << max_height << '\n';
	for(int i = 1; i <= n; i++) {
		h[i] = max_height - h[i];
		sum_h[i] = sum_h[i-1] + h[i];
		cerr << h[i] << ' ';
	}
	cerr << '\n';
	// the problem becomes:
	// find the highest pyramid by adding at most T bricks
	
	auto getPyramidSum = [&](int l, int peak, int r, int peak_height) {
		int len_r = (r - peak + 1);
		ll sum_r = 1LL * len_r * (len_r + 1) / 2 + (peak_height - len_r) * len_r;
		int len_l = (peak - l + 1);
		ll sum_l = 1LL * len_l * (len_l + 1) / 2 + (peak_height - len_l) * len_l;

		return sum_l + sum_r - peak_height;
	};

	auto isAbleToBuild = [&](ll expected_height) {
		unordered_map<ll, int> M;
		vector<int> l(n+1), r(n+1);
		for(int i = 1; i <= n; i++) {
			M[h[i] - i - 1] = i;
			M[h[i] - i] = i;
			l[i] = M[expected_height - i];
		}
		M.clear();
		for(int i = n; i >= 1; i--) {
			M[h[i] + i - 1] = i;
			M[h[i] + i] = i;
			if(!M.count(expected_height + i))
				r[i] = n+1;
			else r[i] = M[expected_height + i];
		}

		// for(int i = 1; i <= n; i++) {
		// 	cerr << l[i] << ' ' << r[i] << '\n';
		// }

		for(int i = 1; i <= n; i++) {
			int sum_pyramid = getPyramidSum(l[i] + 1, i, r[i] - 1, expected_height);
			int sum_height = sum_h[r[i] - 1] - sum_h[l[i]];
			// cerr << i << ' ' << sum_pyramid << ' ' << sum_height << '\n';
			if(sum_pyramid - sum_height <= T)
				return true;
		}
		return false;
	};

	ll L = *max_element(h.begin(), h.end()), R = T;
	while(L <= R) {
		ll mid = (L+R) >> 1;
		if(isAbleToBuild(mid))
			L = mid + 1;
		else R = mid - 1;
	};
	cerr << L - 1 << '\n';
	cout << max_height - L + 1 << '\n';
}
