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
	string start = "";
	string end = "";
	for(int i = 1; i <= n; i++) {
		int d; cin >> d;
		start += (char)(d + '0');
		end += (char)(i + '0');
	}
	map<string, int> len;
	len[start] = 0;
	queue<string> q;
	q.push(start);
	while(!q.empty()) {
		string u = q.front();
		q.pop();
		for(int i = 2; i <= n; i++) {
			string tmp = u;
			reverse(tmp.begin(), tmp.begin() + i);
			if(!len.count(tmp)) {
				len[tmp] = len[u] + 1;
				q.push(tmp);
			}
		}
	}
	cout << len[end] << '\n';
}
