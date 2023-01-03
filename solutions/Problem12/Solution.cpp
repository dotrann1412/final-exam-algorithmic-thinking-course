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
const int MAXN = 3e5 + 5;

int main() {
	io
	int S; cin >> S;
	for(int dx = 0; dx <= S*S; dx++) {
		int sqr_dy = S - dx * dx;
		int dy = sqrt(sqr_dy);
		if(dy*dy == sqr_dy) {
			cout << 0 << ' ' << 0 << '\n'; // p0
			cout << dx << ' ' << dy << '\n'; // p1
			cout << dx+dy << ' ' << dy-dx << '\n'; // p3
			cout << dy << ' ' << -dx << '\n'; // p2
			return 0;
		}
	}
	cout << "Impossible" << '\n';
	// prove: 
	// (p0p1)^2 + (p1p3)^2 = (p0p3)^2
	// ez
}
