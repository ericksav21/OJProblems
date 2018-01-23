#include <iostream>
#include <vector>
#include <utility>

#define MAXN 210

using namespace std;

vector<int> adj[MAXN];

void clearv() {
	for(int i = 0; i < MAXN; i++) {
		adj[i].clear();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(true) {
		int n, edges, u, v;
		cin >> n;
		if(n == 0)
			break;

		adj.clear();
		cin >> edges;
		clearv();

		for(int i = 0; i < edges; i++) {
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}

	return 0;
}