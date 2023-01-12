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
const int MAXN = 105;

int a[MAXN][MAXN];
int s[MAXN][MAXN];

int main() {
	io
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];

	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			if(a[i][j] == 1) {
				s[i][j] = min({s[i][j-1], s[i-1][j], s[i-1][j-1]}) + 1;
				if(ans < s[i][j])
					ans = s[i][j];
			}else s[i][j] = 0;
		}
	cout << ans << '\n';
}
