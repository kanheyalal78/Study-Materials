#include<bits/stdc++.h>
using namespace std;
#define Jay_JAGANATH ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long 
#define lld long long double
#define sz(a) int((a).size())
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ppb pop_back
#define mp make_pair 
#define ff first   
#define ss second
#define INF 1e18   
ll mod = 1e9+7;
ll MOD = 998244353;

class Love {
    vector<vector<char>> grid;
    int n, m, lx, ly;
    vector<vector<int>> vis, ans;
public:

    void dfs(int x, int y) {
        int count = 0;
        bool f = 0;

        if(x-1>=0) {
            if(grid[x-1][y] == 'L') f = 1;
            if(grid[x-1][y] != '#' && !vis[x-1][y]) {
                count++;
            }
        }
        if(x+1<n) {
            if(grid[x+1][y] == 'L') f = 1;
            if(grid[x+1][y] != '#' && !vis[x+1][y]) {
                count++;
            }
        }
        if(y-1>=0) {
            if(grid[x][y-1] == 'L') f = 1;
            if(grid[x][y-1] != '#' && !vis[x][y-1]) {
                count++;
            }
        }
        if(y+1<m) {
            if(grid[x][y+1] == 'L') f = 1;
            if(grid[x][y+1] != '#' && !vis[x][y+1]) {
                count++;
            }
        }
        if(x ==1 && y == 0) {
            cout << count << endl;
        }
        vis[x][y] = 1;
        if(f && count <= 2 ) {
            ans[x][y] = 1;
        } else if(count <= 1) {
            ans[x][y] = 1;
        } else {
            return;
        }
        if(x-1>=0 && !vis[x-1][y] && grid[x-1][y] != '#') {
            dfs(x-1, y);
        }
        if(x+1<n && !vis[x+1][y] && grid[x+1][y] != '#') {
            dfs(x+1, y);
        }
        if(y-1>=0 && !vis[x][y-1] && grid[x][y-1] != '#') {
            dfs(x, y-1);
        }
        if(y+1<m && !vis[x][y+1] && grid[x][y+1] != '#') {
            dfs(x, y+1);
        }
    }

    void solve() {
        cin >> n >> m;
        grid.assign(n, vector<char> (m));
        vis.assign(n, vector<int> (m, 0));
        ans.assign(n, vector<int> (m, 0));

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin >> grid[i][j];
                if(grid[i][j] == 'L') {
                    lx = i, ly = j;
                }
            }
        }
        // vis[lx][ly] = 1;
        int x = lx, y = ly;
        if(x-1>=0 && !vis[x-1][y] && grid[x-1][y] != '#') {
            dfs(x-1, y);
        }
        if(x+1<n && !vis[x+1][y] && grid[x+1][y] != '#') {
            dfs(x+1, y);
        }
        if(y-1>=0 && !vis[x][y-1] && grid[x][y-1] != '#') {
            dfs(x, y-1);
        }
        if(y+1<m && !vis[x][y+1] && grid[x][y+1] != '#') {
            dfs(x, y+1);
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '#' || grid[i][j] == 'L') {
                    cout << grid[i][j];
                } else {
                    cout << (ans[i][j] ? '+' : '.');
                }
            }
            cout << endl;
        }
    }
};

int32_t main() {
    Jay_JAGANATH;   
    cout.tie(NULL);
    int t=1;
    cin >> t;
    while(t--) {
        Love lol;
        lol.solve();
    }
    #ifndef ONLINE_JUDGE
        cerr << "\nTime: " << (float)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    #endif
}
 
/*


    
*/
