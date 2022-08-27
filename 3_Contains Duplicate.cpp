#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_map>

using namespace std;

bool solve(int nums[], int n){
	bool ans = false;
	
	unordered_map<int,int> mp;

	for(int i = 0; i < n; i++){
		if(mp.find(nums[i]) != mp.end()){
			ans = true;
			break;
		}
		mp[nums[i]] = nums[i];
	}
	return ans;
}

int main(){
	int n; 
	cin >> n;
	int ar[n];
	for(int i = 0; i < n; i++){
		cin >> ar[i];
	}


	cout << solve(ar, n);

	return 0;
}