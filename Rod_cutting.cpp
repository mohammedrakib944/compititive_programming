// Rod cutting problem 
//Md. Rakibuzzaman

#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<string.h>
#include<cstring>

using namespace std;

// Rod cutting function
int cutting(int price[], int n)
{
   int DP[n+1];
   DP[0] = 0;
   int i, j;

   for (i = 1; i<=n; i++)
   {
       int max_val = INT_MIN;
       for (j = 0; j < i; j++)
         max_val = max(max_val, price[j] + DP[i-j-1]);
       DP[i] = max_val;
   }
 
   return DP[n];
}
 
int main()
{
    int length = 8;
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};

    cout << cutting(price, length) << endl;

    return 0;
}