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
	int k, n, m;
	cin >> k >> n >> m;
	vector<int> v;
	for(int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;
		v.push_back(max(a, b));
	}
	sort(v.begin(), v.end(), greater<int>());
	cout << accumulate(v.begin(), v.begin() + m + n, 0) << '\n';
}
