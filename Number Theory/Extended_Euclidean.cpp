#include<iostream>
using namespace std;


// question find x and y such that ax + by = gcd(a, b)


// a, b, g = gcd(a, b)

// // find x, y such that ax + by = g

// // Euclidean algo

// gcd(a, b) = gcd(b, a % b); base case b = 0, a = gcd(a, b)

// for base case b = 0, a = gcd(a, b), x = 1 && y = 0  (ax + by) 



// Transition a, b -> b, a % b

// bw + (a % b)t = g  -----(1)

// a mod b = a - (floor(a / b) * b)   -----(2)

// bw + at - (floor(a / b) * b)t = g 
// bw + at - floor(a / b) * t * b = g 

// at + b(w - floor(a / b) * t) = g  { (ax + by) = g }

// x -> t 
// w -> w - t *  floor(a / b)


int extended_gcd(int a, int b, int &x, int &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int t = 0, w = 0;
	int gg = extended_gcd(b, a % b, w, t);
	x = t;
	y = w - t * (a / b);
	return gg; // gg -> gcd
} 

 
int main() {
	int a = 12, b = 8;
	int x = 0, y = 0;
	int g = extended_gcd(a, b, x, y);
	cout << g << " " << x << " " << y << '\n';
}