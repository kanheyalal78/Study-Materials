#include<bits/stdc++.h>
using namespace std;


class DSU {
	int *parent;
	int *rank;

public:
	DSU(int n) {
		parent = new int[n+1];
		rank = new int[n+1];
		for(int i=0;i<=n;i++) {
			parent[i] = i;
			rank[i] = 1;
		}
	}

	int findParent(int node) {
		if(node == parent[node]) {
			return node;
		}
		// return findParent(parent[node]);
		return parent[node] = findParent(parent[node]); // path compression
	}

	void unite (int u, int v) {
		u = findParent(u);
		v = findParent(v);

		if(rank[u] < rank[v]) {
			parent[u] = v;
		} else if(rank[u] > rank[v]) {
			parent[v] = u;
		} else {
			parent[v] = u;
			rank[u]++;
		}
	}
};



int main() {
	DSU dsu = DSU(10);
	int n;
	cin >> n;
	while(n--) {
		int u, v;
		cin >> u >> v;
		dsu.unite(u, v);
	}
	// if u and v belongs to the same components or not
	if(dsu.findParent(2) != dsu.findParent(3)) {
		cout << "Not same";
	} else {
		cout << "Same component";
	}
}