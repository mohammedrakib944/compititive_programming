#include<bits/stdc++.h>

using namespace std;

bool isShorted(int ar[], int n){
	if(n == 0) return true;
	if(ar[n] > ar[n-1]){
		return isShorted(ar, n-1);
	}else{
		return false;
	}

}

int main (){
	int n;
	cin >> n;
	int ar[n];

	for(int i = 0; i < n; i++){
		cin >> ar[i];
	}

	cout << isShorted(ar, n-1);
}