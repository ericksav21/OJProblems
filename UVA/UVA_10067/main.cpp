#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 1000

using namespace std;

vector<int> init(4);
vector<int> target(4);
vector<vector<int> > forb;
bool mark[4];
int mmin, cnt;

void clean() {
	for(int i = 0; i < 4; i++) {
		init[i] = target[i] = mark[i] = 0;
	}
	forb.clear();
	mmin = MAXN;
}

bool check(vector<int> act) {
	for(int i = 0; i < act.size(); i++) {
		bool flag = true;
		for(int j = 0; j < 4; j++) {
			if(act[j] != forb[i][j]) {
				flag = false;
				break;
			}
		}
		if(flag) {
			return true;
		}
	}

	return false;
}

void solve(vector<int> act, int n) {
	if(n == 4) {
		cout << cnt << endl;
		mmin = min(mmin, cnt);
	}
	for(int i = 0; i < 4; i++) {
		if(mark[i]) {
			continue;
		}
		if(n == 0) {
			cnt = 0;
		}
		bool fl = false, fr = false;
		int cl = 0, cr = 0;
		int aux = act[i];
		for(int j = aux; j != target[i]; j = (j + 1) % 10, cr++) {
			//cout << j << endl;
			act[i] = j;
			if(check(act)) {
				fr = true;
				break;
			}
		}
		for(int j = aux; j != target[i]; j = (j - 1 + 10) % 10, cl++) {
			act[i] = j;
			if(check(act)) {
				fl = true;
				break;
			}
		}
		if(fr == true && fl == true) {
			continue;
		}

		act[i] = target[i];
		mark[i] = true;
		solve(act, n + 1);
		act[i] = aux;
		mark[i] = false;
		cnt += min(cr, cl);
	}
}

int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	int n, m;
	cin >> n;
	while(n--) {
		clean();
		for(int i = 0; i < 4; i++) {
			cin >> init[i];
		}
		for(int i = 0; i < 4; i++) {
			cin >> target[i];
		}
		cin >> m;
		for(int i = 0; i < m; i++) {
			vector<int> vaux(4);
			for(int j = 0; j < 4; j++) {
				cin >> vaux[j];
			}
			forb.push_back(vaux);
		}
		solve(init, 0);
		cout << mmin << endl;
	}

	return 0;
}