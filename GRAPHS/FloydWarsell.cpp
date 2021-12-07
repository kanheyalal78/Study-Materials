#include<bits/stdc++.h>
using namespace std;

// all pairs shortest path
// it can detect effective -ve edge weight cycles
// if dist from a node to that becames -ve instead of 0 then it have -ve edge weight cycles   

struct node {
    int u,v,wt;
};
vector<vector<int>> FloydWarsell(vector<node>edges, int n) {
    vector<vector<int>> dist(n+1, vector<int> (n+1, 2e9));
    for(int i=0;i<=n;i++) {
        dist[i][i] = 0;
    }
    for(auto it : edges) {
        dist[it.u][it.v] = min(dist[it.u][it.v], it.wt); 
    }
    for(int k=0;k<=n;k++) {
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=n;j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // dist from i to j through k
            }
        }
    }
    return dist;
}

int main() {

}