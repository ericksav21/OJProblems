#include <iostream>
#include <vector>
#include <utility>
#include <stack>

#define MAXN 210

using namespace std;

vector<int> adj[MAXN];
bool vis[MAXN];
int col[MAXN];

void clearv() {
	for(int i = 0; i < MAXN; i++) {
		adj[i].clear();
		vis[i] = col[i] = 0;
	}
}

bool dfs() {
	stack<int> S;
	S.push(0);
	vis[0] = col[0] = 1;

	while(!S.empty()) {
		int u = S.top(); S.pop();

		for(int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			//Check the color
			if(!col[v]) {
				col[v] = (col[u] == 1 ? 2 : 1);
			}
			else if(col[u] == col[v]) {
				//Same color, the graph cannot be bicolored :(
				return false;
			}

			if(!vis[v]) {
				vis[v] = true;
				S.push(v);
			}
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(true) {
		int n, edges, u, v;
		cin >> n;
		if(n == 0)
			break;

		cin >> edges;
		clearv();

		for(int i = 0; i < edges; i++) {
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		if(dfs()) {
			cout << "BICOLORABLE.\n";
		}
		else {
			cout << "NOT BICOLORABLE.\n";
		}
	}

	return 0;
}