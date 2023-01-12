// https://oj.vnoi.info/problem/shhv
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
	int x;
	vector<int> a(1);
	while(cin >> x)
		a.push_back(x);
	int X = a.back();
	a.pop_back();
	int n = a.size() - 1;
	
	// prepare factorize array
	vector<ll> F(n+1);
	F[0] = 1;
	for(int i = 1; i <= n; i++)
		F[i] = F[i-1] * i;

	// solve query 1
	ll ans = 1;
	vector<bool> vi(n+1);
	for(int i = 1; i <= n; i++) {
		int cnt = 0;
		for(int j = 1; j <= n; j++)
			cnt += (j < a[i] && !vi[j]);
		ans += F[n-i] * cnt;
		vi[a[i]] = 1;
	}
	cout << ans << '\n';

	// solve query 2
	fill(vi.begin(), vi.end(), 0);
	fill(a.begin(), a.end(), 0);
	X--;
	for(int i = 1; i <= n; i++) {
		int ord = 0, cnt = 0;
		while(X >= F[n-i]) {
			X -= F[n-i];
			ord++;
		}
		for(int j = 1; j <= n; j++) {
			if(!vi[j] && cnt == ord) {
				a[i] = j;
				vi[j] = 1;
				break;
			}
			if(!vi[j]) cnt++;
		}
	}
	for(int i = 1; i <= n; i++)
		cout << a[i] << " \n"[i == n];
}
