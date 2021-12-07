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
ll MOD = 998244353;

int seg[4 * 100005];

void build(int arr[], int ind, int low, int high) {
	if(low == high) {
		seg[ind] = arr[low];
		return;
	}
	
	int mid = (low + high) /2;
	build(arr, 2*ind+1, low, mid);
	build(arr, 2*ind+2, mid+1, high);
	
	seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
}

int query(int ind, int low, int high,int l, int r) {
	if(low>=l && high <= r) {
		return seg[ind];
	}
	if(high < l || low > r) {
		return INT_MIN;
	}
	int mid = (low + high) /2;
	int left = query(2*ind+1, low, mid, l, r);
	int right = query(2*ind+2, mid+1, high, l, r);
	return max(left, right);	
}

void update(int ind, int sl, int sr, int pos, int newVal) {
	if(sr < pos || sl > pos) {
		return;
	}
	if(sl == sr) {
		seg[ind] = newVal;
		return;
	}
	int mid = (sl + sr) /2;
	update(2*ind+1, sl, mid, pos, newVal);
	update(2*ind+2, mid+1, sr, pos, newVal);
	
	seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
}




int main() {

    cout << "hi" << endl;
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	build(arr, 0, 0, n-1);
	
	int q;
	cin >> q;
	while(q--) {
		int t;
		cin >> t;
		if(t == 1) {
			int x, y;
			cin >> x >> y;
			cout << x << " " << y << endl;
			cout << query(0, 0, n-1, x-1, y-1) << endl;
		} else {
			int pos, newV;
			cin >> pos >> newV;
			arr[pos-1] = newV;
			update(0, 0, n-1, pos-1, newV);
		}
		for(int i=0;i<n;i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}

/* 


*/

