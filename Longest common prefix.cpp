Problem link:
https://leetcode.com/problems/longest-common-prefix/description/

solution:
    string longestCommonPrefix(vector<string>& vs) {
        string ans = "";
        int n = vs.size();
        if(n == 0) return ans;

        sort(vs.begin(), vs.end());

        string a = vs[0];
        string b = vs[n-1];

        for(int i = 0; i < a.length(); i++){
            if(a[i] == b[i]){
                ans.push_back(a[i]);
            }else{
                break;
            }
        }
        return ans;
    }
