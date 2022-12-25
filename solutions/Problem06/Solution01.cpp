#include <bits/stdc++.h>

using namespace std;

#define init(file_name) freopen(filename.in, "r", stdin); freopen(filename.out, "w", stdout)
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(a) a.begin(), a.end()

#define ll long long
#define vt vector
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define db double

const ll MaxN = 1e5 + 5;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const db eps = 1e-5;
const db pi = acos(-1);

struct Node
{
	int val;
	Node* next;

	Node(): val(0), next(nullptr) {};
	Node(int v, Node* n = nullptr): val(v), next(n) {}

	struct Comparator 
	{
		bool operator() (Node* first, Node* second) {
			return first->val > second->val;
		}
	};
};


void solve() {
	int n; cin >> n;
	priority_queue<Node*, vector<Node*>, Node::Comparator> heap;
	
	string stringbuffer; getline(std::cin, stringbuffer); // ignore empty line

	for (int i = 0; i < n; ++i) {
		getline(std::cin, stringbuffer);
		stringstream ss(stringbuffer);
		Node *head, *cur; head = cur = nullptr;
		
		for (int tmp; ss >> tmp; ) {
			if (!head) head = cur = new Node(tmp);
			else cur->next = new Node(tmp), cur = cur->next;
		}

		if (head)
			heap.push(head);
	}

	Node *head, *cur; head = cur = nullptr;
	while (heap.size()) {
		Node* t = heap.top(); heap.pop();
		
		if (t->next) 
			heap.push(t->next), t->next = nullptr;

		if (!head) head = cur = t;
		else cur->next = t, cur = cur->next;
	}

	for (cur = head; cur; cur = cur->next) {
		cout << cur->val << ' ';
	}

	for (cur = head; cur; ) {
		Node *tmp = cur->next;
		delete cur;
		cur = tmp;
	}
}

int main() {
	fastio();
	int t = 1; // cin >> t;
	while(t--) solve();
	return 0;
}