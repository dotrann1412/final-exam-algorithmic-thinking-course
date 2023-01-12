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
#define EPS 1e-6
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const double PI = acos(-1.0);
const int MAXN = 3e5 + 5;

struct Point{
	int x, y;
};

ld intersectionArea(Point c1, Point c2, int R) {
	ld d = sqrt((c2.x - c1.x) * (c2.x - c1.x) + (c2.y - c1.y) * (c2.y - c1.y));

	if(d > 2*R)
		return 0;
	
	if(d == 0)
		return PI * R * R;

	ld alpha = acos((d * d) / (2 * R * d)) * 2;
	ld a = 0.5 * alpha * R * R - 0.5 * R * R * sin(alpha);
	return a * 2.0;
}

int main() {
	io
	int x1, y1, x2, y2, R;
	cin >> x1 >> y1 >> x2 >> y2 >> R;
	cout << fixed << setprecision(3);
	cout << (ld)R*R*PI*2.0 - intersectionArea({x1, y1}, {x2, y2}, R) << '\n';
}
