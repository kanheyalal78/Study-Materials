#include<bits/stdc++.h>
using namespace std;

// minimum spanning tree
// deletes edges so that at the end total edge weight become minimun  
// at the end there will be no cycles in the graph

// in minimum spanning tree if we want to add an edge then we can always find another edge to discard

class DSU {
	int *parent;
	int *rank;
public:
	DSU(int n) {
		parent = new int[n+1];
		rank = new int[n+1];
		for(int i=0;i<=n;i++) {
			parent[i] = i;
			rank[i] = i;
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

struct node {
	int u, v, wt;
};

bool comp(node a, node b) {
	return a.wt < b.wt;
}

int Kruskal(vector<node> &edges, int n) {
	DSU d = DSU(n);
	sort(edges.begin(), edges.end(), comp);
	int cost = 0;
	vector<node> mst;
	for(auto it : edges) {
		if(d.findParent(it.u) != d.findParent(it.v)) {
			cost += it.wt;
			mst.push_back(it);
			d.unite(it.u, it.v);
		}
	}
	// return mst; if edges require
	return cost;
}
int main() {

}