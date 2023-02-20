class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans;

        int isNine = 0;
        
        for(int i = 0; i < n; i++){
            if(nums[i] == 9) isNine++;
            ans.push_back(nums[i]);
        }

        if(isNine == ans.size()){
            ans[0] = 1;
            for(int i = 1; i < n; i++){
                ans[i] = 0;
            }
            ans.push_back(0);
            return ans;
        }

        if(ans[n-1] == 9){
            for(int i = n-1; i >= 0; i--){
                if(ans[i] == 9){
                    ans[i] = 0;
                }else{
                    ans[i]++;
                    break;
                }
            }
        }else{
            ans[n-1]++;
        }

        return ans;

    }
};