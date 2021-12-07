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


const int MAXN = 1e5 + 5;
int seg[4 * MAXN];

// ind in all function -> index in seg
int build(int arr[], int ind, int l, int r) {
    if(l == r) {
        seg[ind] = arr[l];
        return arr[l];
    }
    int mid = (l + r)/2;

    seg[ind] = build(arr, 2*ind+1, l, mid) + build(arr, 2*ind+2, mid+1, r);
    return seg[ind];
}

// ind - index in seg
// l r -> required range
// sl, sr -> range of seg[ind]
int query(int ind, int sl, int sr, int l, int r) {
    if(sl >= l && sr <= r) { // total overlap
        return seg[ind];
    }
    if(sr < l || sl > r) {  // no overlap
        return 0;
    }
    //partial overlap
    int mid = (sl + sr) /2;

    return query(2*ind+1, sl, mid, l, r) + query(2*ind+2, mid+1, sr, l , r);
}

// pos -> index in arr
// diff -> new value of arr[pos] - old value
// adding diff in all the nodes which contains pos
void update(int ind, int sl, int sr, int pos, int diff) {
    if(sl > pos || sr < pos) {
        return;
    }
    seg[ind] += diff;

    if(sl != sr) {
        int mid = (sl + sr) /2;
        update(2*ind+1, sl, mid, pos, diff);
        update(2*ind+2, mid+1, sr, pos, diff);
    }
}

void solve() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    build(arr, 0 , 0, n-1);
    cout << query(0, 0, n-1, 0, 2);
}


int main() 
{ 
    Jay_JAGANATH;
    cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    solve();	
} 





/* 



*/
