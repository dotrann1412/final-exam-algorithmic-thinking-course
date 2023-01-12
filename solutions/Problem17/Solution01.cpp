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
	int n; cin >> n;
	
	auto getBit = [&](int val, int bit)-> bool {
		return (val>>bit)&1;
	};

	int maxState = (1<<9) - 1;
	for(int state = 1; state <= maxState; state++) {
		int cur = 0, base = 1;
		for(int bit = 0; bit < 9; bit++) {
			if(getBit(state, bit))
				cur = cur + base;
			base *= 10;
		}
		if(cur % n == 0)
			return cout << cur, 0;
	}
}
