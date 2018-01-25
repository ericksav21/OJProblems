#include <bits/stdc++.h>
using namespace std;


#define NMAX 100000 + 10
typedef vector<int> vi;


void leerV(vector<int> &v) {

	for(int i=0; i<4; i++)
		cin >> v[i];

}


void coutV(vector<int> &v) {

	for(int i=0; i<4; i++)
		cout << v[i] << ' ';

	cout << endl;

}


int v2int(vector<int> &v) {

	int ans = 0;

	for(int i=0; i<4; i++)
		ans += v[i]*pow(10, 3-i);

	return ans;

}


vector<int> mueve(vi v, int i, int di) {

	v[i] = (v[i] + di + 10)%10;

	return v;

}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int visitado[NMAX], ok[NMAX];
	int n, m;
	cin >> n;
	while(n--) {

		vector<int> si(4), sf(4), ss(4);
		memset(visitado, -1, sizeof(visitado));
		memset(ok, 1, sizeof(ok));

		leerV(si);
		leerV(sf);

		//coutV(si);
		//coutV(sf);

		int target = v2int(sf);

		//cout << target << endl;

		cin >> m;

		for(int i=0; i<m; i++) {

			leerV(ss);
			ok[v2int(ss)] = 0;

		}

		queue<vector<int> > S;

		S.push(si);
		visitado[v2int(si)] = 0;

		while(!S.empty()) {

			ss = S.front();
			S.pop();

			int intSS = v2int(ss);

			if(intSS == target)
				break;


			for(int i=0; i<4; i++) {

				vi ns = mueve(ss, i, 1);
				int num = v2int(ns);

				if(ok[num] && visitado[num] == -1) {

					S.push(ns);
					visitado[num] = visitado[intSS] + 1;


				}

				ns = mueve(ss, i, -1);
				num = v2int(ns);

				if(ok[num] && visitado[num] == -1) {

					S.push(ns);
					visitado[num] = visitado[v2int(ss)] + 1;


				}

			}


		}

		cout << visitado[target] << '\n';

	}

	return 0;
}
