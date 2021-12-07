#include<bits/stdc++.h>
using namespace std;
// strongly connected components




class Kosaraju {
    vector<vector<int>> SCC;
public:
    void dfs(int node, stack<int> &s,vector<int> &vis, vector<int> adj[]) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, s, vis, adj);
            }
        }
        s.push(node);
    };

    void revDFS(int node, vector<int> &vis, vector<int> &v, vector<int> transpose[]) {
        v.push_back(node);
        vis[node]=1;
        for(auto it : transpose[node]) {
            if(!vis[it]) {
                revDFS(it, vis, v, transpose);
            }
        }
    }

    Kosaraju(vector<int> adj[], int n) {
        // topo sort
        stack<int> s;
        vector<int> vis(n+1, 0);
        for(int i=1;i<=n;i++) {
            if(!vis[i]) {
                dfs(i, s, vis, adj);
            }
        }
        // transpose
        vector<int> transpose[n+1];
        for(int i=1;i<=n;i++) {
            vis[i] = 0;
            for(auto it : adj[i]) {
                transpose[it].push_back(i);
            }
        }
        while(!s.empty()) {
            int node = s.top();
            s.pop();
            if(!vis[node]) {
                vector<int> v;
                revDFS(node, vis, v, transpose);
                SCC.push_back(v);
            }
        }
    }

    vector<vector<int>> getSCC() {
        return SCC;
    }
};







void dfs(int node, stack<int> &s,vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, s, vis, adj);
        }
    }
    s.push(node);
};

void revDFS(int node, vector<int> &vis, vector<int> &v, vector<int> transpose[]) {
    v.push_back(node);
    vis[node]=1;
    for(auto it : transpose[node]) {
        if(!vis[it]) {
            revDFS(it, vis, v, transpose);
        }
    }
}


vector<vector<int>> Kosaraju(vector<int> adj[], int n) {
    // topo sort
    stack<int> s;
    vector<int> vis(n+1, 0);
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            dfs(i, s, vis, adj);
        }
    }
    // transpose
    vector<int> transpose[n+1];
    for(int i=1;i<=n;i++) {
        vis[i] = 0;
        for(auto it : adj[i]) {
            transpose[it].push_back(i);
        }
    }
    vector<vector<int>> SCC;
    while(!s.empty()) {
        int node = s.top();
        s.pop();
        if(!vis[node]) {
            vector<int> v;
            revDFS(node, vis, v, transpose);
            SCC.push_back(v);
        }
    }
    return SCC;
}




int main() {
    
}