#include<bits/stdc++.h>
using namespace std;


vector<int> adj[100005];
int parent[100005][20];

int inTime[100005];
int outTime[100005]; 
int ti= 0;

void binaryLifting(int v, int p) {
    parent[v][0] = p;

    inTime[v] = ti++;


    for(int i=1;i<20;i++) {
        if(parent[v][i-1] == -1) parent[v][i] = -1;
        else parent[v][i] = parent[parent[v][i-1]][i-1];
    }
    for(auto i : adj[v]) {
        if(i != p) {
            binaryLifting(i, v);
        }
    }

    outTime[v] = ti;
}


bool is_Ancestor(int a, int b) {
    if(inTime[a] <= inTime[b] && outTime[a] >= outTime[b]) 
        return true;
    else
        return false; 
}


// finding lowest common ancestor in O( log N )

// checking 2^i ancestor of a is also a ancestor of b ? -> skip
// if not ancestor then move to that 2^i ancestor then check from there  
// at the last we will reach a node whose 1st ancestor (2^0) is 
// the lowest common ancestor of a , b

int lowest_Common_Ancestor(int a , int b) {
    if(is_Ancestor(a, b)) return a;
    if(is_Ancestor(b, a)) return b;

    for(int i=19; i>=0; i--) {
        if(parent[a][i] != -1 && !is_Ancestor(parent[a][i], b)) {
            a = parent[a][i];
        }
    }

    return parent[a][0];
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
    
    cout << lowest_Common_Ancestor(2, 3);
}

int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    // cin >> t;

    while(t--) {
        solve();
    }
}
