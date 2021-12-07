#include<bits/stdc++.h>
using namespace std;
// after n-1 relaxation we will get shortest path
// if we perform nth relaxation and shortest path decreases again then then it has 
// -ve weight cycles 

struct node {
    int u, v, wt;
};

void BellManFord(int root, vector<node> &edges, int n) {
    vector<int> dist(n+1, 1e9);
    dist[root] = 0;
    for(int i=0;i<n-1;i++) {
        for(auto it : edges) {
            if(dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }
    // return dist; if shortest path require
    for(auto it : edges) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            // return true; has -ve weight cycles 
        }
    }
}

int main() {

}