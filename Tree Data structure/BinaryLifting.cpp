#include<bits/stdc++.h>
using namespace std;


// for finding kth ancestor of a node in O(1)
vector<int> adj[100005];
int parent[100005][20];


// finding 2^0, 2^1, 2^2, 2^3, 2^4, 2^5 ...... 2^20 ancestor
// of node v

// 2^4 ancestor of a = 2^3 ancestor of 2^3 ancestor of a
// 2^4 = 2^3 + 2^3

void binaryLifting(int v, int p) {
    parent[v][0] = p;
    for(int i=1;i<20;i++) {
        if(parent[v][i-1] == -1) parent[v][i] = -1;
        else parent[v][i] = parent[parent[v][i-1]][i-1];
    }
    for(auto i : adj[v]) {
        if(i != p) {
            binaryLifting(i, v);
        }
    }
}

// dividing k into 2^a + 2^b + 2^c + .....
// jumping from 2^a ancestor -> 2^b ancestor
// for finding 10th ancestor of a
// 1010 = 1000 + 10
// goto 2nd ancestor(10) of a then
// goto 8th ancestor(1000) from 2nd ancestor of a 

int kth_Ancestor(int a, int k) {
    if(k == 0) return a;

    for(int i=0; i<20; i++) {
        if((k >> i) & 1) {
            a = parent[a][i];
        }
        if(a == -1)   {
            return a;
        }
    }
    return a;
}


void solve() {
    int n;
    cin >> n;
    while(n--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    binaryLifting(1, -1);
    
    cout << kth_Ancestor(11, 10);
}

int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    cin >> t;

    while(t--) {
        solve();
    }
}
