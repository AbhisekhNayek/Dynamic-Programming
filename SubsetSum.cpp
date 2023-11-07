#include <bits/stdc++.h> 

bool solution(int index, int target, vector<int> &arr,vector<vector<int>>&dp){

    if(target==0){
        return true;
    }

    if(index==0){
        return arr[0]==target;
    }

    if(dp[index][target]!=-1){
        return dp[index][target];
    }

    bool NotTake = solution(index-1,target,arr,dp);
    bool take= false;

    if(target>=arr[index]){
        take = solution(index-1,target-arr[index],arr,dp);
    }

    return dp[index][target]=take or NotTake;

}

bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<vector<int>>dp(n , vector<int>(k+1, -1));

    return solution(n-1,k,arr,dp);
}
