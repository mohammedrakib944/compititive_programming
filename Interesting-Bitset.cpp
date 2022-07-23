#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>

using namespace std; 

#define ll long long int
#define pb(n) push_back(n)
#define el "\n"

const int MX = 32;
const int siz = 1e5+5;

void solve(){
	ll c;
	cin >> c;
	bitset<MX> m(c);
	bitset<MX> a(c),b(c);
	a.reset();
	b.reset();
	ll left = -1;
	for(int i = MX-1; i>=0; i--){
		if(m[i]==1){
			left = i;
			break;
		}
	}

	a[left] = 1;
	b[left] = 0;
	for(int i= left-1; i>=0; i--){
		
		if(m[i] == 1){
			a[i] = 0;
			b[i] = 1;
		}else{
			a[i] = 1;
			b[i] = 1;
		}

	}
	ll u,v;
	u = a.to_ulong();
	v = b.to_ulong();
	cout << u*v << el;
}	 

// A^A=0 and A^0=A

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t=1;
	cin >> t;
	while(t--) 
	solve();

	return 0;
}