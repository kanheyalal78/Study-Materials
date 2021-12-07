#include<bits/stdc++.h>
using namespace std;

// don't work for -ve weight edges cycles

vector<int> Dijkstra(int root, vector<pair<int,int>> adj[], int n) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dis(n+1, 2e9);
    dis[root] = 0;
    pq.push({0, root});
    while(!pq.empty()) {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();
        if(dist != dis[prev]) continue;
        for(auto it : adj[prev]) {
            int next = it.first;
            int nextDist = it.second;
            if(dis[next] > dis[prev] + nextDist) {
                dis[next] = dis[prev] + nextDist;
                pq.push({dis[next], next});
            }
        }
    }
    return dis;
}


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

}