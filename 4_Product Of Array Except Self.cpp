#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_map>

using namespace std;

void solve(int nums[], int n){
	int pre[n];
	int post[n];
	int ans[n];

	pre[0] = nums[0];
	post[n-1] = nums[n-1];

	for (int i = 0; i < n - 1; ++i)
	{
		pre[i + 1] = pre[i] * nums[i + 1];
	}

	for(int i = n - 1; i >= 0; i--){
		post[i - 1] = post[i] * nums[i-1];
	}
	
	ans[0] = post[1];
	ans[n-1] = pre[n-2];

	for (int i = 1; i < n - 1; ++i)
	{
		ans[i] = pre[i - 1] * post[i + 1];
	}

	for (int i = 0; i < n; ++i)
	{
		cout << ans[i] << " ";
	}
	

}

int main(){
	int n; 
	cin >> n;
	int ar[n];
	for(int i = 0; i < n; i++){
		cin >> ar[i];
	}

	solve(ar, n);

	return 0;
}