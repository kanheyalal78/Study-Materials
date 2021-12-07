#include<bits/stdc++.h>
using namespace std;

class SparseTable {
	vector<vector<int>> table, sumTable;
	vector<int> log;
	int maxLog;
public:
	SparseTable(int n, vector<int> &arr) {
		log.resize(n+1);
		log[1] = 0;
		for(int i=2;i<=n;i++) {
			log[i] = 1 + log[i/2];
		}
		maxLog = log[n];
		build(arr);
	}
	void build(vector<int> &arr) {
		int n = arr.size();
		table.assign(n, vector<int>(25));
		sumTable.assign(n, vector<int>(25, 0));
		for(int l=n-1;l>=0;l--) {
			for(int w=0;w<25;w++) {
				int r = l + (1 << w) - 1;
				if(r >= n) break;
				if(w == 0) table[l][w] = arr[l];
				else table[l][w] = min(table[l][w-1], table[l + (1 << (w-1))][w-1]); 

				if(w == 0) sumTable[l][w] = arr[l];
				else sumTable[l][w] = sumTable[l][w-1] + sumTable[l + (1 << (w-1))][w-1];
			}
		}
	}
	int queryIdempotent(int l, int r) {
		int w = r - l;
		int power = log[w];
		return min(table[l][power] , table[r - (1 << power)+1][power]);
	}
	int queryNormal(int l, int r) {
		int sum=0;
		for(int j=21;j>=0;j--) {
			if((1 << j) <= r - l + 1) {
				sum += sumTable[l][j];
				l += (1 << j);
			} 
		}
		return sum;
	}
};


int main() {

}