//For shorted Data: iterative , O(N) time and O(1) space;

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void solve(int ar[], int target, int n){
	int p1 = 0;
	int p2 = n-1;

	for(int i = 0; i < n; i++){
		int sum = ar[p1] + ar[p2];
		if(sum == target){
			cout << p1 << " " << p2 << endl;
			return;
		}else if(sum < target){
			p1++;
		}else if(sum > target){
			p2--;
		}
		if(p1 == p2){
			cout << "Not possible" << endl;
		}
	}
}

int main(){
	int n; 
	int target;
	cin >> n >> target;
	
	int ar[n];

	for(int i = 0; i < n; i++){
		cin >> ar[i];
	}

	solve(ar, target, n);

	return 0;
}

2) //for any data - hash map method, O(N) time and space

#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> solve(int nums[], int target, int n){
	vector<int> ans;
	unordered_map<int, int> hash;
	for(int i = 0; i < n; i++){
		if(hash.find(target - nums[i]) != hash.end()){
			ans.push_back(hash[target - nums[i]]+1);
			ans.push_back(i+1);
			return ans;
		}
		hash[nums[i]] = i;
	}
	return ans;
}

int main(){
	int n; 
	int target;
	cin >> n >> target;
	
	int ar[n];

	for(int i = 0; i < n; i++){
		cin >> ar[i];
	}

	vector<int> show;

	show = solve(ar, target, n);

	for(int i = 0; i < show.size(); i++){
		cout << show[i] << " ";
	}

	return 0;
}