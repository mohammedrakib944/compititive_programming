//Method 1 using Hash Map - O(N) time and space;

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int solve(int nums[], int n){
	int ans = 0;
	int aux[n];
	int mx = 0;
	for (int i = n-1; i >= 0; --i)
	{
		mx = max(nums[i], mx);
		aux[i] = mx;
	}

	for (int i = 0; i < n-1; ++i)
	{
		mx = aux[i] - nums[i];
		ans = max(mx, ans);
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


// METHOD 2, Time O(N) space O(1);

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int solve(int nums[], int n){
	int mini = 1e5 + 10;
	int mx = 0;

	for (int i = 0; i < n; ++i)
	{
		int x = nums[i];
		mini = min(x, mini);
		mx = max((nums[i] - mini), mx);
	}
	return mx;
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