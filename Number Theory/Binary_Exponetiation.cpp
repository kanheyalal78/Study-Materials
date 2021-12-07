#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll bin(ll x, ll y, ll m) {
	ll res = 1ll;
	x = x % m;
	while(y > 0) {
		if(y & 1) {
			res = (res * x) % m;
		}
		y = y >> 1;
		x = (x * x) % m;
	}
	return res;
}

int main() {
	ll x , y, m;
	cin >>  x >> y >> m;
	cout << bin(x, y, m);
}