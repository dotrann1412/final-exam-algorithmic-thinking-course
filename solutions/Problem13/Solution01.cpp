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

int cross(Point A, Point B, Point C){
    ll val = 1LL*A.x*(B.y - C.y) + 1LL*B.x*(C.y - A.y) + 1LL*C.x*(A.y - B.y);
	if(val == 0)
		return 0; // coline
	if(val < 0)
		return 1; // clockwise
	return -1; //counter clockwise
}

int main() {
	io
	int n; cin >> n;
	vector<Point> points;
	for(int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		points.push_back({x, y});
	}
	for(int i = 1; i < n; i++) {
		// assume the spliting line is made of 0 and i 
		vector<int> cnt(2);
		for(int j = 0; j < n; j++) {
			int c = cross(points[0], points[i], points[j]);
			if(c < 0) cnt[0]++;
			if(c > 0) cnt[1]++;
		}
		if(cnt[0] == cnt[1])
			return cout << 1 << ' ' << i+1 << '\n', 0;
	}
}
