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

vector<int> G[MAXN];

int sumDown[MAXN], sumUp[MAXN], nchild[MAXN];

void DFS(int u, int pa) {
	nchild[u] = 1;
	for(int v: G[u]) {
		if(v != pa) {
			DFS(v, u);
			nchild[u] += nchild[v];
			sumDown[u] += sumDown[v] + nchild[v];
		}
	}
}

void DFS2(int u, int pa) {
	if(pa > 0) {
		sumUp[u] += (sumUp[pa] + sumDown[pa] - sumDown[u] - nchild[u]);
		sumUp[u] += (nchild[1] - nchild[u]);
	}
	for(int v: G[u])
		if(v != pa) {
			DFS2(v, u);
		}
}

int main() {
	io
	int n; cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	DFS(1, 0);
	DFS2(1, 0);
	ll ans = 0;
	for(int i = 1; i <= n; i++)
		ans += sumUp[i] + sumDown[i];
	cout << ans / 2 << '\n';
}
