#include <bits/stdc++.h>

using namespace std;

int M = 1e9+7;

// Recursive Method
int binaryExp(int a, int b){
	if(b == 0) return 1;	
	int res = binaryExp(a, b/2);
	if(b&1){
		return (a * ((res * 1LL * res) % M)) % M;
	}else{
		return (res * 1LL * res ) % M;
	}
}

// Iteratrative Method (better)
int binaryExp_Iterator(int a, int b){
	int ans = 1;
	while(b){
		if(b & 1){
			ans = (ans * 1LL * a) % M;
		}
		a = (a * 1LL * a) % M;
		b >>= 1;
	}
	return ans;
}

int main() {

	int a,b;
	cin >> a >> b;
	cout << binaryExp(a, b) <<"\n";
	cout << binaryExp_Iterator(a, b);
}
