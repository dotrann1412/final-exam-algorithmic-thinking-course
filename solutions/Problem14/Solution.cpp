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

struct Point{
	int x, y;
};

int main() {
	io
	int n; cin >> n;
	vector<ll> S(n);
	vector<Point> points;
	for(int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		points.push_back({x, y});
	}
	ll area = 1LL*(points[n-1].x + points[0].x) * (points[n-1].y - points[0].y);
	for(int i = 1; i < n; i++) {
		S[i] = 1LL*(points[i-1].x + points[i].x) * (points[i-1].y - points[i].y);
		area += S[i];
		S[i] += S[i-1];
	}
	area = abs(area);
	ii ans;
	ll cur_diff = -1;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++) {
			ll cur_area = S[j] - S[i] + 1LL*(points[j].x + points[i].x) * (points[j].y - points[i].y);
			cur_area = abs(cur_area);
			if(cur_diff == -1 || cur_diff > abs(area - 2*cur_area)) {
				cur_diff = abs(area - 2*cur_area);
				ans = {i, j};
			}
		}
	cout << ans.fi + 1 << ' ' << ans.se + 1 << '\n';
}
