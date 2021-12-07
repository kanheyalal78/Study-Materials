#include<bits/stdc++.h>
using namespace std;

void TopologyDFS(int v, vector<int> adj[], vector<int> &visited, vector<int> &ans) {
    visited[v] = true;
    for(auto i : adj[v]) {
        if(!visited[i]) {
            TopologyDFS(i, adj, visited, ans);
        }
    }
    ans.push_back(v);
}

vector<int> Topology(int n, vector<int> adj[]) {
    vector<int> visited(n+1, false);
    vector<int> ans;
    for(int i=1;i<=n;i++) {
        if(!visited[i]) {
            TopologyDFS(i, adj, visited, ans);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}



int main() {

}


