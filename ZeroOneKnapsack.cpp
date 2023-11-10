#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));

    for(int W=weight[0]; W<=maxWeight; W++){

        dp[0][W] = value[0];
    }

    for(int ind=1; ind<n; ind++){

        for(int W=0; W<=maxWeight; W++){

            int notTake = 0 + dp[ind-1][W];
            int take = INT_MIN;

            if(weight[ind]<=W){
                take = value[ind] + dp[ind-1][W-weight[ind]];
            }
            dp[ind][W] = max(take, notTake);
        }
    }
    return dp[n-1][maxWeight];
}
