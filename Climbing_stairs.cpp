https://leetcode.com/problems/climbing-stairs/description/


class Solution {
public
    int climbStairs(int n) {
        int ar[50];
        ar[0] = 1;
        ar[1] = 1;
        ar[2] = 2;

        for(int i = 3; i = 45 ; i++){
            ar[i] = ar[i-1] + ar[i-2];
        }

        return ar[n];
    }
};