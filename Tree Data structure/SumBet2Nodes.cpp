#include<bits/stdc++.h>
using namespace std;


vector<int> adj[100005];
int parent[100005][20];

int inTime[100005];
int outTime[100005]; 
int ti= 0;

int res[100005][20];
// value of a node i.e. 5th node has value 56
int val[100005];

int depth[100005];

void binaryLifting(int v, int p) {
    parent[v][0] = p;

    if(p != -1) res[v][0] = val[p];
    else res[v][0] = 0;

    inTime[v] = ti++;


    for(int i=1;i<20;i++) {
        if(parent[v][i-1] == -1)  {
            parent[v][i] = -1;
            res[v][i] = res[v][i-1];
        }
        else {
            parent[v][i] = parent[parent[v][i-1]][i-1];
            res[v][i] = res[v][i-1] + res[parent[v][i-1]][i-1];
        } 
    }
    for(auto i : adj[v]) {
        if(i != p) {
            binaryLifting(i, v);
        }
    }

    outTime[v] = ti;
}



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


bool is_Ancestor(int a, int b) {
    if(inTime[a] <= inTime[b] && outTime[a] >= outTime[b]) 
        return true;
    else
        return false; 
}



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


// k -> jump to kth node from a
int kth_result(int a, int k) {
    int ans = val[a];

    for(int i=0; i<20; i++) {
        if((k >> i) & 1) {
            ans += res[a][i];
            a = parent[a][i];
        }

        if(a == -1) {
            return a;
        }
    }
    return ans;
}

void dfs(int v, int p, int d) {
    depth[v] = d;
    for(auto i : adj[v]) {
        if(i != p) {
            dfs(i, v, d+1);
        }
    }
}

int calSum(int a , int b) {
    int lca = lowest_Common_Ancestor(a, b);
    int sum1 = kth_result(a, depth[lca] - depth[a]);
    int sum2 = kth_result(b, depth[lca] - depth[b]);
    return sum1 + sum2 - val[lca];
}



int findSumBet2Nodes (int a , int b) {
    int lca = lowest_Common_Ancestor(a, b);
    // sum(lca, a) + sum (lca , b)
    int sum1 = val[a];
    int sum2 = val[b];
    for(int i=19;i>=0;i--) {
        if(parent[a][i] != -1 && !is_Ancestor(a, lca)) {
            sum1 += res[a][i];
            a = parent[a][i];
        }
    }

    for(int i=19;i>=0;i--) {
        if(parent[b][i] != -1  && !is_Ancestor(b , lca)) {
            sum2 += res[b][i];
            b = parent[b][i];
        }
    }
    // lca added 2 times 
    return sum1 + sum2 - val[lca] ; 
}

// another approach
// store depth of each node
// find depth of lca of a , b
// ans = kth_result(a, depth[lca]-depth[a]) + kth_result(b, depth[lca] - depth[b])
// return ans - val[lca]


void solve() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> val[i];
    
    while(n--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    binaryLifting(1, -1);

    kth_result(10, 5); // sum of nodes between 10 & its 5th ancestor

    findSumBet2Nodes(10 , 20); // sum between a & b
    
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

