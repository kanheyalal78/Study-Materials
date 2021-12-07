#include<bits/stdc++.h>
using namespace std;
#define Jay_JAGANATH ios_base::sync_with_stdio(false); cin.tie(NULL)
#define sz(a) int((a).size())
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ll long long 
#define INF 1e18 
ll mod = 1e9+7;       
   
 
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}




void solve() {
    ll  x = 1e6;
    ll a = x * x;
    cout << a << endl;

}

int main() {

    Jay_JAGANATH;
    cout.tie(NULL);
      
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif
    
    int t=1;
    // cin >> t;

    while(t--) {
        solve();
    }

    
    // #ifndef ONLINE_JUDGE
    //     cerr << "\nTime: " << (float)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    // #endif
}

/* 


*/